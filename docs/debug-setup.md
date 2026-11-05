# 这个工程是怎么"按 F5 就能调试"的

VSCode 本身不认识 C。它只做三件事:

1. 按 `launch.json` 找到 gdb 和要调试的 exe;
2. 按 `preLaunchTask` 找到 `tasks.json` 里 **label 完全相同** 的那个任务;
3. 把编译命令 **原样** 交给系统去执行(用哪种方式执行,由任务的 `type` 决定)。

以前 `tasks.json` 用的是 `"type": "shell"`,命令要交给一个 shell 去解析 —— 这就是
为什么参数里必须手写双引号,也是为什么它暗地里依赖"集成终端默认 profile 是 MSYS2 bash"。
现在改成 `"type": "process"`,这条链上**没有任何 shell**,那些隐形依赖一起消失了。

---

## 现在的链路

```text
F5
 └─ launch.json (type: cppdbg → ms-vscode.cpptools 的调试适配器)
     ├─ preLaunchTask: "build C program"
     │    └─ tasks.json (type: process, 不经过 shell)
     │         ├─ command: C:/msys64/ucrt64/bin/gcc.exe      ← 绝对路径,不查 PATH
     │         ├─ args: ["-g","-O0",...,"{file}","-o","{fileDirname}/{...}.exe"]
     │         │                                    ↑ 数组直传,没有引号、没有转义
     │         ├─ options.env.PATH += C:\msys64\ucrt64\bin   ← gcc 找得到自己的 DLL
     │         └─ options.cwd = ${fileDirname}
     │              └─ 产出 <源文件目录>/<源文件名>.exe (含 DWARF)
     ├─ program: ${fileDirname}\${fileBasenameNoExtension}.exe   ← 与产物路径严格对应
     ├─ miDebuggerPath: C:/msys64/ucrt64/bin/gdb.exe             ← 绝对路径
     └─ cwd: ${fileDirname}
```

## 四个文件各管什么

| 文件 | 负责 | 写错了会怎样 |
| --- | --- | --- |
| `launch.json` | 用哪个 gdb、调试哪个 exe、调试前跑哪个任务、程序在哪运行 | `miDebuggerPath` 错 → `Unable to start debugging` |
| `tasks.json` | 怎么把 `.c` 编成带调试信息的 `.exe` | label 不匹配 → 找不到 preLaunchTask |
| `c_cpp_properties.json` | **只**喂给 IntelliSense(红波浪线、跳转、补全) | 不影响编译,只影响编辑器体验 |
| `settings.json` | 工作区级的工具链/格式化/静态分析参数 | 工具路径错 → 该功能静默失效 |

## 三个必须知道的关键点

### 1. `/ucrt64/bin` 必须在 PATH 里 —— 否则 gcc 静默失败

MSYS2 的 gcc 在编译时会去调 `cc1.exe` / `as.exe` / `ld.exe`,这些程序又依赖
`/ucrt64/bin` 下的 `libisl`、`libmpc`、`zlib1.dll` 等。实测:

```text
PATH 里没有 /ucrt64/bin : gcc ... → exit 1,而且**一个字都不打印**,exe 没生成
PATH 里有 /ucrt64/bin   : gcc ... → exit 0,exe 正常生成
```

这就是为什么 `tasks.json` 里写了 `options.env.PATH`。少了这一段,你会看到
"preLaunchTask terminated with exit code 1" 但完全不知道错在哪。

`gdb` 则不需要这个 —— `launch.json` 用的是绝对路径,而且 gdb 自身的 DLL 就在它旁边。

### 2. `type: process` 下不要再写引号

`shell` 类型是把整串命令拼成一行交给 bash/cmd 解析,`${file}` 展开成
`C:\Users\...` 这种反斜杠路径,不加引号会被 bash 当转义符吃光:

```text
shell 类型,不加引号: cc1.exe: fatal error: C:Usersweath...hello_world.c: No such file or directory
```

`process` 类型把每个参数作为独立的一项传给 gcc,VSCode 自己负责必要的引号,
所以 args 里写 `"${file}"` 就好 —— **带上引号反而会让文件名变成 `"...c"`**。

### 3. `-g` 是调试的开关

`-g` 让 gcc 写入 DWARF 调试信息。有它时:

```text
(gdb) break main
Breakpoint 1 at 0x1400014ed: file hello_world.c, line 7    ← 能映射到源码行
```

没它时断点只有一个裸地址 —— 能跑,但断点打不中、变量看不到、单步跳的是汇编。

## 自查清单(在 VSCode 集成终端里跑)

```bash
which gcc && gcc --version | head -1     # 应该指向 /ucrt64/bin/gcc
which gdb && gdb --version  | head -1    # 应该指向 /ucrt64/bin/gdb

# 手动复现一次构建(等价于 Ctrl+Shift+B)
gcc -g -O0 -Wall -Wextra -std=gnu17 \
    src/chapter/chapter_one/hello_world.c \
    -o src/chapter/chapter_one/hello_world.exe

# 确认调试信息真的写进去了
gdb -batch -ex 'break main' src/chapter/chapter_one/hello_world.exe
```

## 故障排查

| 现象 | 原因 | 处理 |
| --- | --- | --- |
| `preLaunchTask ... exit code 1`,任务终端一片空白 | PATH 里缺 `/ucrt64/bin` | 检查 `options.env.PATH` 是否被删 |
| `gcc: error: ... No such file or directory`,路径里反斜杠不见了 | 退回了 `shell` 类型却还留着引号写法 | 要么改回 `process`,要么按 shell 规则加引号 |
| `preLaunchTask '...' terminated with exit code 1` | 编译报错 | 看"问题"面板,`$gcc` 匹配器已把错误解析进去了 |
| 断点是空心圆 / `未绑定断点` | 没 `-g`,或调试的不是刚编出来的 exe | 检查 `program` 与 `-o` 是否一致 |
| `scanf` 输入没反应 | 程序跑在调试控制台里 | `launch.json` 的 `console` 应为 `integratedTerminal` |
| `Unable to start debugging` | gdb 路径不对 | 核对 `miDebuggerPath` 是否存在 |
| 中文输出乱码 | Windows 控制台默认 GBK | 源文件输出保持 ASCII,或 `chcp 65001` |

## 以后要拆多文件、多目录怎么办

现在这条命令是 **单文件** 假设:每个 `.c` 都自带 `main()`,一个文件一个程序。
等真的开始写 `foo.c + foo.h + main.c` 时,有两种走法:

1. **手写 Makefile**(推荐,顺便学构建):把 `command` 换成
   `C:/msys64/ucrt64/bin/mingw32-make.exe`,`args` 改成 `["-j"]`。
2. **上 CMake**:装 CMake Tools 扩展,由它接管编译与调试配置。

注意:不要写成 `"${fileDirname}/*.c"` 之类去让 shell 通配 —— 这个库里同一个目录下
往往有好几个各自带 `main()` 的独立程序,一起链接会 `multiple definition of main`。

## 关于 clang-format

项目根目录多了 `.clang-format`,按你现有代码风格写的:函数大括号独占一行、
控制语句大括号同行、`} else {` 同行、4 空格缩进、`case` 缩进一层。
`Shift+Alt+F` 就不会把代码改成 LLVM 的 2 空格风格了。

想改成"保存即格式化",把 `.vscode/settings.json` 里
`"[c]".editor.formatOnSave` 改成 `true`。

---

## 附录:改造前那套为什么也能跑

老配置是 `"type": "shell"` + 裸 `gcc`,它能工作是因为下面四件事同时成立:

1. **默认终端 profile 是 MSYS2 UCRT64 bash**(写在全局
   `%APPDATA%\Code\User\settings.json`,`--login` + `MSYSTEM=UCRT64`)。
   `shell` 类型的任务用的就是这个 profile,login 时 `/etc/profile` 会把
   `/ucrt64/bin` 加进 PATH —— 所以裸 `gcc` 才找得到。
   这就是 `tasks.json` 依赖了一个**工作区之外**的全局设置,也是最难 debug 的地方。
2. **`CHERE_INVOKING=1`** 阻止 login shell `cd $HOME`。没有它,任务的工作目录
   会变成 `/home/weath`,相对路径全废:
   ```text
   不带: pwd → /home/weath
   带  : pwd → /c/Users/weath/code/c_learning/src/chapter/chapter_one
   ```
3. **参数里的双引号**挡住了 bash 对反斜杠的转义(见上文第 2 点)。
4. **`-g`** 让 gcc 写入 DWARF,`miDebuggerPath` 又给了 gdb 绝对路径。

现在改成 `process` 后,第 1、2、3 条都不再需要 —— 只有第 4 条(编译器参数、调试器路径)
仍然留在配置里,而它们是本来就该显式写出来的东西。

## 备份

原 `.vscode/backup-originals/`（改动前的四个原始文件）已于 **2026-11-05** 删除，之后本仓库**没有配置回滚点**（项目未纳入 git）。

如需还原 11-03 之前的旧配置：按上文各节重建，或从**系统回收站**取回（当时是按"删除到回收站"处理的，尚未清空回收站时还能恢复）。
