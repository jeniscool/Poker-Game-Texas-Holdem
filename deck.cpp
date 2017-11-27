/* File: deck.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Deck class.
 *
 */

#include <cstdlib>
#include <ctime>
#include "deck.h"
#include <string>
        
// create a standard 52-card deck
void Deck::createDeck()
{
for (int s = Card::Spade ; s < SUITS; s++) {
	for (Card::cPoints p = CARD_START; p < RANKS + CARD_START; p++) {
		Card::cSuits suit = static_cast<Card::cSuits>(s);
		Card newcard(suit, p);
		deck.push_back(newcard);
	}
}
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck()
{
srand(time(0));
Card temp;
for(int i = deck.size() - 1; i >= 1; i--)
{	
	int j = rand() % (i+1);
	temp = deck[j];
	// swap first and second card
	deck[j] = deck[i];
	deck[i] = temp;
}
}

// return a card from the tail of the deck
Card Deck::deal_a_card()
{
Card* last;
last = &deck[deck.size() -1];
deck.pop_back();
return *last;
}
