//
//  main.cpp
//  RoundsOfShuffleDeck
//
//  Created by Michael Dautermann on 8/16/18.
//  Copyright © 2018 Michael Dautermann. All rights reserved.
//

#include <iostream>

struct Card {
    struct Card *next;
    long index;
};

typedef struct Deck {
    struct Card *start;
    struct Card *end;
} Deck;




int main(int argc, const char * argv[]) {
    Deck deck;
    
    int numOfCards, index = 0, start = 1, i = 0, j = 0, ret = 0;
    if(argc >  1)
    {
        numOfCards = atoi(argv[1]);
    }
    else
    {
        printf("Enter the number of cards in a deck: Max to be 52!\n");
        scanf("%d", &numOfCards);
    }

    std::cout << "Hello, World!\n";

    // initialize the deck
    Card *lastCard = NULL;
    for(index = 0; index < numOfCards; index++)
    {
        Card *card = (Card *)malloc(sizeof(Card));
        card->index = index;
        if(lastCard != NULL)
        {
            lastCard->next = card;
            deck.end = card;
        } else {
            deck.start = card;
            deck.end = card;
        }
        
        lastCard = card;
    }
    
    
    
    
    return 0;
}
