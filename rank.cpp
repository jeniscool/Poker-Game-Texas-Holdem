/* File: rank.cpp
 * Course: CS216-004
 * Project: Programming Project2/Lab9
 * Purpose: the implementation of member functions for the rank class
 *
 */

#include "rank.h"
#include <iomanip>

// Default constructor rank as not being ranked
Rank::Rank()
{
	kind = NoRank;
	point = 0;
}

// Alternate constructor
// create a Rank object with specified ranking name and points
Rank::Rank(hRanks r, rPoints p)
{
if (r == HighCard || r == Pair || r == ThreeOfAKind || r == Straight || r == Flush || r == FullHouse || r == FourOfAKind || r == StraightFlush)
	this->kind = r;
else
	this->kind = NoRank;
if (p >= 2 && p <= 14)
	this->point = p;
else
	this->point = 0;
}

// Display a description of the hand-ranking category to standard output
void Rank::print()
{

cout << "The rank is: " << this->kind << "(";
	switch(this->point){
		case 11: cout << setw(3) << "J)";
		case 12: cout << setw(3) << "Q)";
		case 13: cout << setw(3) << "K)";
		case 14: cout << setw(3) << "A)";
	}
}
