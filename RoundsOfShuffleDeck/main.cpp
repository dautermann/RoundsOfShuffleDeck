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

Deck *initializeADeck() {
    Deck *newDeck = (Deck *)malloc(sizeof(Deck));
    
    newDeck->start = NULL;
    newDeck->end = NULL;
    
    return newDeck;
}

void printDeck(Deck *deck) {
    Card *card = deck->start;
    
    do {
        std::cout << card->index;
        
        card = card->next;
        
    } while (card != NULL);
    
    std::cout << "\n";
}

bool validateDeck(Deck *deck, int numberOfCards) {

    Card *eachCard = deck->start;
    int cardIndex = 1;
    
    do {

        if (eachCard->index != cardIndex++)
        {
            return false;
        }
        eachCard = eachCard->next;

    } while(eachCard != NULL);
    
    return true;
}

Deck * shuffleDeck(Deck *originalDeck) {
    Deck *newDeckOnTable = initializeADeck();
    Card *firstCard = originalDeck->start;
    do {
        
#ifdef I_WANTED_TO_DEBUG
        std::cout << "remain of originalDeck: ";
        Card *aCard = firstCard;
        do {
            std::cout << aCard->index;
            aCard = aCard->next;
        } while(aCard != NULL);
        std::cout << "\n";

        if (newDeckOnTable->start != NULL)
        {
            std::cout << "newDeckOnTable: ";
            printDeck(newDeckOnTable);
            std::cout << "\n";
        }
#endif
        
        Card *secondCard = firstCard->next;

        if (newDeckOnTable->start != NULL)
        {
            firstCard->next = newDeckOnTable->start;
        } else {
            firstCard->next = NULL;
            newDeckOnTable->end = firstCard; // this will end up being the last card of the new deck on the table
        }
        
        //  Take the top card off the deck and set it on the table
        newDeckOnTable->start = firstCard;

        //  Take the next card off the top and put it on the bottom of the deck in your hand.
        if (secondCard == NULL)
        {
            firstCard = NULL;
        } else {
            originalDeck->end->next = secondCard;
            originalDeck->end = secondCard;
            firstCard = secondCard->next;
            secondCard->next = NULL;
        }
        
    // Continue steps 1 and 2 until all cards are on the table.  This is a round.
    } while (firstCard != NULL);
    
    return newDeckOnTable;
}

int main(int argc, const char * argv[]) {
    Deck *originalDeck = initializeADeck();
    
    int numOfCards;
    if(argc >  1)
    {
        numOfCards = atoi(argv[1]);
    }
    else
    {
        printf("Enter the number of cards in a deck: \n");
        scanf("%d", &numOfCards);
    }
    
    // initialize the deck
    Card *lastCard = NULL;
    for(int index = 1; index <= numOfCards; index++)
    {
        Card *card = (Card *)malloc(sizeof(Card));
        card->index = index;
        if(lastCard != NULL)
        {
            lastCard->next = card;
            originalDeck->end = card;
        } else {
            originalDeck->start = card;
            originalDeck->end = card;
        }
        
        lastCard = card;
    }
    
    int shuffleCount = 0;
    bool originalOrder = false;
    Deck *deckToReorder = originalDeck;
    do {
        shuffleCount++;
        Deck *reorderedDeck = shuffleDeck(deckToReorder);
#ifdef I_WANTED_TO_DEBUG
        std::cout << "final reordered deck: ";
        printDeck(reorderedDeck);
        std::cout << "\n";
#endif
        originalOrder = validateDeck(reorderedDeck, numOfCards);
        free(deckToReorder);
        deckToReorder = reorderedDeck;
    } while(originalOrder == false);
    
    free(deckToReorder);
    std::cout << "how many rounds to put deck back into original order = " << shuffleCount << "\n";
    return 0;
}
