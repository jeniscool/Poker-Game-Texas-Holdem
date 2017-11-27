/* File: card.h
 * Course: CS216-00x
 * Project: Programming Project 2
 * Purpose: the declaration for the Card class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

// define the unicode for four suits for display purpose
const char SPADE[] = "\xe2\x99\xa0";
const char CLUB[] = "\xe2\x99\xa3";
const char HEART[] = "\xe2\x99\xa5";
const char DIAMOND[] = "\xe2\x99\xa6";

class Card 
{
    public:
        // Type definition for the suits of a playing card.
        // Invalid means the Card object has not been initialized.
        // Note: outside Card member functions, refer this type using Card::cSuits, 
        // Card::Spades, Card::Hearts, ...
        //
        typedef enum {Invalid, Spade, Club, Heart, Diamond} cSuits;

        // Type definition for the point value of a playing card.
        // A point value of 0 means the Card object has not been initialized.
        // J = 11, Q = 12, K = 13, A = 14.
        // A point value of 1 is not used.
        // Note: outside Card member functions, refer this type using Card::cPoints
        //
        typedef unsigned int cPoints;

        // Default constructor.
        // We allow uninitialized Cards to be created.
        // This allows arrays of Cards.
        // Uninitialized cards should have Invalid for its suit
        // and 0 for its points.
        Card(); 

        // Alternate constructor
        // Create a Card with specified suit and points.
        Card(cSuits s, cPoints p);

        // compare with another Card object passed in as parameter: other
        // if the object your are working on has higher point than other, return 1;
        // if the object your are working on has lower point than other, return -1;
        // otherwise, return 0
        int compareTo(Card other);

        // Display a description of the Card object to standard output.
        // The output should look like:
        //   the sign of suit, followed by the point, then followed by the sign of suit again
        void print();
        
        // Assign the friendship to the class named PokerHand
        friend class PokerHand;

    private:
        cSuits suit;        // suit of the card
        cPoints point;    // point value of the card
};
#endif  /* CARD_H */
