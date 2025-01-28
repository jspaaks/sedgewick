#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    CLUBS = 0,
    HEARTS,
    DIAMONDS,
    SPADES,
} Suit;

typedef enum {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

char * print_rank_name(Rank);
char * print_suit_name(Suit);

int main (void) {
    srand(time(NULL));
    int c;
    while (true) {
        Card card = {
            .suit = rand() % 3,
            .rank = 2 + rand() % 12,
        };
        fprintf(stdout, "%s of %s.", print_rank_name(card.rank), print_suit_name(card.suit));
        c = getchar();
        if (c == 'q') {
            exit(EXIT_SUCCESS);
        } else if (c == '\n') {
            continue;
        } else {
            while (getchar() != '\n')
                continue;
        }
    }
}

char * print_rank_name (Rank rank) {
    switch (rank) {
        case (TWO):
            return "2";
        case (THREE):
            return "3";
        case (FOUR):
            return "4";
        case (FIVE):
            return "5";
        case (SIX):
            return "6";
        case (SEVEN):
            return "7";
        case (EIGHT):
            return "8";
        case (NINE):
            return "9";
        case (TEN):
            return "10";
        case (JACK):
            return "Jack";
        case (QUEEN):
            return "Queen";
        case (KING):
            return "King";
        case (ACE):
            return "Ace";
        default:
            return "";
    }
}

char * print_suit_name (Suit suit) {
    switch (suit) {
        case (CLUBS):
            return "Clubs";
        case (HEARTS):
            return "Hearts";
        case (DIAMONDS):
            return "Diamonds";
        case (SPADES):
            return "Spades";
        default:
            return "";
    }
}
