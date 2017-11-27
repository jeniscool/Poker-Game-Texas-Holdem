/* File: pokerhand.cpp
 * Course: CS216-004
 * Project: Project 2
 * Purpose: the implementation of the member functions for the PokerHand class.
 *
 */

#include "pokerhand.h"
#include <iomanip>
#include <iostream>

//---------------------------member functions-----------------------------

// Default constructor to create blank poker hand
PokerHand::PokerHand()
{
	for (int i = 0; i < FIVE; i++) {
		cards[i].suit = Card::Invalid;
		cards[i].point = 0;
		}
	hand_rank.kind = Rank::NoRank;
	hand_rank.point = 0;
}

// It should store the FIVE cards
// given as parameters in the cards[] array.
// if size is not FIVE, display "Invalid number of cards!"
// It should also immediately evaluate the hand, determine
// its rank: ranking kind and the card value
void PokerHand::setPokerHand(Card in_hand[], int size)
{
	if (size == FIVE) {
		//deal cards
		for (int i=0; i < FIVE; i++){
			cards[i].suit = in_hand[i].suit;
			cards[i].point = in_hand[i].point;
		}
		sort();
		if (!isStraightFlush())
			if (!isFourOfAKind())
				if(!isFullHouse())
					if(!isFlush())
						if(!isStraight())
							if(!isThreeOfAKind())
								if(!isPair())
									isHighCard();
	}
	else
		cout << "Invalid number of cards!" << endl;
}

// Compare this hand versus otherHand according
// to the rules of poker. 
// Returns a negative number (< 0) 
// if this hand loses to the otherHand.
// Returns a positive number (> 0) 
// if this hand beats the otherHand.
// Returns zero if it's a tie.
int PokerHand::compareHand(const PokerHand &otherHand)
{
	if (hand_rank.kind > otherHand.hand_rank.kind)
		return 1;
	else if (hand_rank.kind < otherHand.hand_rank.kind)
		return -1;
	else {
		if (hand_rank.point > otherHand.hand_rank.point)
			return 1;
		else if (hand_rank.point < otherHand.hand_rank.point)
			return -1;
		else
			return 0;
	}
}

// print rank and point
void PokerHand::print()
{
	cout << "Five Cards in order:" << endl;
	for (int i = 0; i < FIVE; i++) {
		cards[i].print();
	}
	cout << "\nIts rank is: ";
	switch (hand_rank.kind) {
		case 1: cout << "High Card(";
			break;
		case 2: cout << "Pair(";
			break;
		case 3: cout << "Three of a Kind(";
			break;
		case 4: cout << "Straight(";
			break;
		case 5: cout << "Flush(";
			break;
		case 6: cout << "Full House(";
			break;
		case 7: cout << "Four of a Kind(";
			break;
		case 8: cout << "Straight Flush(";
			break;
	}
	switch (hand_rank.point) {
		case 14: cout << " A)" << endl;
			break;
		case 13: cout << " K)" << endl;
			break;
		case 12: cout << " Q)" << endl;
			break;
		case 11: cout << " J)" << endl;
			break;
		default: cout << setw(2) << hand_rank.point << ")" << endl;
			break;
	}
}

//return the rank of this hand
Rank PokerHand::getRank() const
{
	return hand_rank;
}

//-------------------bool expressions to determine rank-------------------------

// Returns true if the hand is a StraightFlush
bool PokerHand::isStraightFlush()
{
	if (isAllOneSuit() == true && isSequence() == true){
		hand_rank.kind = Rank::StraightFlush;
		hand_rank.point = cards[0].point;
		return true;
	}
	else
		return false;
}

// Returns true if the hand is a Four of a Kind
bool PokerHand::isFourOfAKind()
{
	int foak = 0;
        int highp = 2;
        for (int i = 0; i < FIVE-3; i++){
                if (cards[i].point == cards[i+1].point && cards[i].point == cards[i+2].point && cards[i].point == cards[i+3].point){
                                foak++;
                                if (cards[i].point > highp)
                                        highp = cards[i].point;
                }
        }
        if (foak == 1){
                hand_rank.kind = Rank::FourOfAKind;
                hand_rank.point = highp;
                return true;
        }
        else
                return false;
}

// Returns true if the hand is a Full House
bool PokerHand::isFullHouse()
{
	// check for: x x y y y
	if (cards[0].point == cards[1].point && cards[2].point == cards[3].point && cards[3].point == cards[4].point){
		hand_rank.kind = Rank::FullHouse;
		hand_rank.point = cards[4].point;
		return true;
	}
	// check for: x x x y y
	if (cards[0].point == cards[1].point && cards[1].point == cards[2].point && cards[3].point == cards[4].point) {
		hand_rank.kind = Rank::FullHouse;
		hand_rank.point = cards[0].point;
		return true;
	}
	else
		return false;
}

// Returns true if the hand is a Flush
bool PokerHand::isFlush()
{
	int highp = 2;
	if (isAllOneSuit() == true){
		for (int i = 0; i < FIVE; i++){
			if (cards[i].point > highp)
				highp = cards[i].point;
			hand_rank.kind = Rank::Flush;
			hand_rank.point = highp;
			return true;
		}
	}
	else
		return false;
}

// Returns true if the hand is a Straight
bool PokerHand::isStraight(){
	int highp = 2;	
	if(isSequence() == true) {
		highp = cards[0].point;
		hand_rank.kind = Rank::Straight;
		hand_rank.point = highp;
        	return true;
	}
        else
        return false;
}

// Returns true if the hand is a Three of a Kind
bool PokerHand::isThreeOfAKind()
{
	int toak = 0;
	int highp = 2;
	for (int i = 0; i < FIVE-2; i++){
                if (cards[i].point == cards[i+1].point && cards[i].point == cards[i+2].point){
                        	toak++;
				if (cards[i].point > highp)
					highp = cards[i].point;
		}
	}
	if (toak == 1){
		hand_rank.kind = Rank::ThreeOfAKind;
        	hand_rank.point = highp;
        	return true;
	}
	else
        	return false;
}

// Returns true if the hand is a Pair (we consider either one pair or two pairs is a Pair)
bool PokerHand::isPair()
{
	int pairs = 0;
	int highp = 2;
	for (int i = 0; i < FIVE-1; i++) {
		if (cards[i].point == cards[i+1].point) {
			pairs++;
			if (cards[i].point > highp)
				highp = cards[i].point;
		}
	}
	if (pairs == 1 || pairs == 2){
		hand_rank.kind = Rank::Pair;
        	hand_rank.point = highp;
        	return true;
	}
	else
        	return false;
}

// Returns true if the hand is a High Card
bool PokerHand::isHighCard()
{
	int highp = 2;
	for (int i = 0; i < FIVE; i++){
		if (cards[i].point > highp)
			highp = cards[i].point;
	}
	hand_rank.kind = Rank::HighCard;
	hand_rank.point = highp;
	return true;
}

//----------------------private functions--------------------------
//cannot be called outside of the class

// to help sort the FIVE cards in decreasing order by card points
void PokerHand::sort()
{
	bool swapped = true;
	int j = 0;
	Card temp;
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < FIVE-j; i++) {
			if (cards[i].point < cards[i+1].point) {
				temp = cards[i];
				cards[i] = cards[i+1];
				cards[i+1] = temp;
				swapped = true;
			}
		}
	}
}

// to help decide if FIVE cards are all of one suit
bool PokerHand::isAllOneSuit()
{
	for (int i = 0; i < FIVE-1; i++)
		if (cards[i].suit != cards[i+1].suit)
			return false;
	return true;
}

// to help decide if FIVE cards are in a continuous sequence
bool PokerHand::isSequence()
{
	// sort in increasing order
	bool swapped = true;
	int j = 0;
	Card temp;
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < FIVE - j; i++) {
			if (cards[i].point > cards[i+1].point) {
				temp = cards[i];
				cards[i] = cards[i+1];
				cards[i+1] = temp;
				swapped = true;
			}
		}
	}
	//check if sequence
	for (int i = 0; i < FIVE-1; i++){
		if (cards[i].point != cards[i+1].point-1) {
			// sort back
			sort();
			return false;
		}
	}
	//sort back
	sort();
	return true;
}
