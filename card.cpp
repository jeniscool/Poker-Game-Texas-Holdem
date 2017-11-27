/* File: card.cpp
 * Course: CS216-00x
 * Project: Lab 7
 * Purpose: the implementation of member functions for the Card class.
 *
 */

#include "card.h"
#include <iomanip>

// Default constructor marks card as invalid
Card::Card() 
{
	suit = Invalid;
	point = 0;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
this->suit = s;
this->point = p;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other)
{
	if (this->point > other.point)
		return 1;
	else if (this->point < other.point)
		return -1;
	else
		return 0;
}

// Display a description of the Card object to standard output   
void Card::print() 
{
	char FACE;
	if (this->point == 11)
		FACE = 'J';
	else if (this->point == 12)
		FACE = 'Q';
	else if (this->point == 13)
		FACE = 'K';
	else if (this->point == 14)
		FACE = 'A';
	if (this->point > 10) {
		if (this->suit == Spade)
                	cout << SPADE << setw(2) << FACE << SPADE << endl;
       		 else if (this->suit == Club)
                	cout << CLUB << setw(2) << FACE << CLUB << endl;
        	else if (this->suit == Heart)
                	cout << HEART << setw(2) << FACE << HEART << endl;
        	else if (this->suit == Diamond)
                	cout << DIAMOND << setw(2) << FACE << DIAMOND << endl;
	}
	else {
		if (this->suit == Spade)
			cout << SPADE << setw(2) << this->point << SPADE << endl;
		else if (this->suit == Club)
			cout << CLUB << setw(2) << this->point << CLUB << endl;
		else if (this->suit == Heart)
			cout << HEART << setw(2) << this->point << HEART << endl;
		else if (this->suit == Diamond)
			cout << DIAMOND << setw(2) << this->point << DIAMOND << endl;
}
}
