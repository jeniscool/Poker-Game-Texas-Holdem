/*
 * Course: CS216-004
 * Project: Project 2
 * Purpose: to implement a game of Texas Hold Em
 *
 */

#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"
#include "card.h"
#include "SortedLinkedList.h"
#include <string>

//magic numbers
const int SEVEN = 7;
const int FIVE = 5;
const int TWO = 2;

using namespace std;

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards);

int main() {
string input = "";
while (input != "Q" && input != "q") {
	
	//create deck
	Deck deck;
	deck.createDeck();

	//shuffle deck 3x
	for (int i = 0; i < 3; i++)
		deck.shuffleDeck();

	vector <Card> Player, Comp, Table;
	// deal two cards to player and comp
	Player.push_back(Card(deck.deal_a_card()));
	Comp.push_back(Card(deck.deal_a_card()));
	Player.push_back(Card(deck.deal_a_card()));
	Comp.push_back(Card(deck.deal_a_card()));

	Table.push_back(Card(deck.deal_a_card()));
	Table.push_back(Card(deck.deal_a_card()));
	Table.push_back(Card(deck.deal_a_card()));
	Table.push_back(Card(deck.deal_a_card()));
	Table.push_back(Card(deck.deal_a_card()));

	//print cards
	cout << "\nThe cards in your hand are:" << endl;
	for (int i=0; i < TWO; i++)
		Player[i].print();

	cout << "\nThe FIVE cards on the deck to share are:" << endl;
	cout << "*************" << endl;
	for (int i=0; i < FIVE; i++)
		Table[i].print();
	cout << "*************" << endl;

	cout << "\nThe cards in computer's hand are:" << endl;
	for (int i=0; i < TWO; i++)
		Comp[i].print();

	// apped card on table to cards in player and comp's hand
	Player.insert(Player.end(), Table.begin(), Table.end());
	Comp.insert(Comp.end(), Table.begin(), Table.end());

	// find best combinations for computer and player
	PokerHand bestP;
	PokerHand bestC;
	//print Player best hand
	cout << "\nPlayer 1: You" << endl;
	bestP = best_FIVE_out_of_SEVEN(Player);
	//print Computer best hand
	cout << "\nPlayer 2: Computer" << endl;
	bestC = best_FIVE_out_of_SEVEN(Comp);

	//determine winner
	if (bestP.compareHand(bestC) > 0)
		cout << "Congratulations, you win the game!" << endl;
	else if (bestP.compareHand(bestC) < 0)
		cout << "Sorry, Computer wins the game." << endl;
	else
		cout << "Tied game!" << endl;

//ask if wants to play again
cout << "\nDo you want to play poker game again (Press ""q"" or ""Q"" to quit the program)" << endl;
getline(cin, input);
if (input == "Q" || input == "q"){
	cout << "\nThank you for using this program!" << endl;
	return 0;
}
}
}

//find best five out of 7
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
{
	PokerHand bestH;
	PokerHand cardsH;

	//check if the parameter is valid
	if (cards.size() != SEVEN) {
		cout << "Invalid Cards, we need SEVEN cards!" << endl;
		return cardsH; //return a PokerHand object by defalut constructor
	}

	//consider all ways of dropping 2 cards
	for (int i; i < SEVEN; i++) {
		for (int j =i+1; j < SEVEN; j++) {
			Card pick[FIVE];
			int index = 0;
			
			//iterate all 7 cards and assign them to pick[]
			for (int k = 0; k < SEVEN; k++) {
				//exclude cards with index of i or j
				if (k == i || k == j)
					continue;
				pick[index] = cards[k];
				index++;
			}
			
			//create a PokerHand with pick[]
			cardsH.setPokerHand(pick, FIVE);

			// see if picked hand is better than best hand
			if (bestH.compareHand(cardsH) < 0)
				bestH = cardsH;

		}
	}

	// Now bestH holds best poker hand among all 21 poker hands
	cout << "*** Best five-card hand ***" << endl;
	bestH.print();
	cout << endl;
	return bestH;
}
