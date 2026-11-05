/* Deals a random hand of cards */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int i;

    int hand_cards, num_rank, num_suit;
    char deck_rank[13] = {'a', '2', '3', '4', '5', '6',
                          '7', '8', '9', 't', 'j', 'q', 'k'};
    char deck_suit[4] = {'c', 'd', 'h', 's'};
    int in_hand[4][13] = {0};

    printf("Enter number of cards in hand: ");
    scanf("%d", &hand_cards);
    srand(time(NULL));

    for (i = 0; i < hand_cards;) {
        num_suit = rand() % 4;
        num_rank = rand() % 13;
        if (in_hand[num_suit][num_rank] == 0) {
            printf("%c%c ", deck_rank[num_rank], deck_suit[num_suit]);
            in_hand[num_suit][num_rank] = 1;
            i++;
        }
    }

    return 0;
}