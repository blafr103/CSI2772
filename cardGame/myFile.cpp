
#include <iostream>
using namespace std;

#include "myFile.h"
#include "Card.h"
#include "CardsSet.h"
#include "Player.h"

#include <cstdlib>
#include <ctime>
#include <string> 

//variables to keep track of current deck size, and current deck position
int currentsize, currPos;


int main() {
	CardsSet packet;
	Player you(packet, false);
	Player me(packet, true);
	char answer[3];
	bool continuous = true;
	cout << "Hello! " << endl;
	while (continuous)
	{
		cout << "A new game? " << endl;
		cin >> answer;
		continuous = answer[0] == 'y';
		if (continuous)
		{
			packet.novSet();
			packet.shuffle();
			packet.take();
			int p1 = you.play();
			if (p1 > 21) {
				cout << "You lost! " << endl;
			}
			else if (p1 == 21) {
				cout << "You won! " << endl;
			}
			else // the computer must play
			{
				int p2 = me.play();
				if (p2 <= 21 && p2 >= p1) {
					cout << "You lost! " << endl;
				}
				else {
					cout << "You won! " << endl;
				}
			}
		}
	}
	return 0;
}

void Card::write() {
	string colour, value;
	

	//convert all colours to a string value
	if (this->col == club) {
		colour = "Clubs";
	}else if (this->col == diamond) {
		colour = "Diamonds";
	}else if (this->col == heart) {
		colour = "Hearts";
	}else if (this->col == spade) {
		colour = "Spades";
	}

	// if the value is 1, 11, 12, or 13, update value to display face name instead of number
	// otherwise it converts the number to string to display	
	if (this->val == 11) {
		value = "Jack";
	}else if (this->val == 12) {
		value = "Queen";
	}else if (this->val == 13) {
		value = "King";
	}else if (this->val == 1) {
		value = "Ace";
	}else{
		value = std::to_string(this->val);
	}
	cout << value << " of " << colour << endl;
}

void CardsSet::novSet() {

	currentsize=0;
	currPos = 0;

	//split deck into 4 parts(for each colour) and then add 13 card values for each color to the set
	//after each card is added, update deck size
	for (int j = 0; j < 4; j++) {
		for (int i = 1; i <= 13; i++) {
			if (j == 0) {
				this->set[(13 * j) + i] = Card(club, i);
				currentsize++;

			}else if (j == 1) {
				this->set[(13 * j) + i] = Card(diamond, i);
				currentsize++;

			}else if (j == 2) {
				this->set[(13 * j) + i] = Card(heart, i);
				currentsize++;

			}else if (j == 3) {
				this->set[(13 * j) + i] = Card(spade, i);
				currentsize++;

			}
		}
	}
}

void CardsSet::shuffle() {
	//temp card to help with swapping
	Card temp;
	//generate random seed
	srand(time(NULL));
	
	//shuffle by swapping each card with a random other card
	for (int i = 0; i < 52; i++){
		//generate random position minus the ones already swapped from head of stack down
		int pos = i + rand() % (52 - i);
		//swap 2 cards by placing data of one in a temporary card
		temp = this->set[i];

		this->set[i] = this->set[pos];

		this->set[pos] = temp;	
	} 
	//reset position to head of stack
	currPos = 1;
}

Card CardsSet::take() {
	//temp variable to 
	Card card;
	//check if deck is empty
	if (currentsize > 0) {
		//save card from top of deck 
		card = this->set[currPos-1];
		//update deck size and position
		currPos++;
		currentsize--;

		//use write() function to print card taken
		cout << "You get Card: ";

		card.write();
	}
	//return card that was taken
	return card;
}

void CardsSet::put(Card k) {
	//add a card at end of set, update set size
	this->set[currentsize] = k;
	currentsize++;
}

Card CardsSet::lookIn(int no) {
	//returns card at position no, -1 because we want top of stack to be 1, not 0
	return this->set[no-1];
}


int Player::play() {
	bool supCard = true;
	int handPoints=0;
	char answer[3];

	

	while (supCard &&(handPoints<=21)) {

		//see if computer or player is playing
		if (this->computer) {
			//add card to computer hand
			this->inHand.put(this->packet.take());
			//calculate points in hand with function countPoints()
			handPoints = this->countPoints();
			supCard = false;
		}
		else if (!this->computer) {
			//see if player wants to take a card, break if not
			cout << "An additionnal Card? ";
			cin >> answer;
			supCard = answer[0] == 'y';
			if (!supCard) {
				break;
			}

			//add card to player hand
			this->inHand.put(this->packet.take());

			//calculate points in hand with function countPoints()
			handPoints = this->countPoints();
		
			cout << handPoints;

		}
	}

	//empty hand and return point count
	this->inHand.empty();

	return handPoints;
}

int Player::countPoints() {
	int totPoints=0;
	Card card;

	for (int i = 1; i <= this->inHand.numCards(); i++) {
		//check to see if we surpassed 21, if not, add 14 to totPoints instead of 1
		if ((totPoints < 21) && (this->inHand.lookIn(i).value()==1)) {
			totPoints += 14;
		}else if (totPoints<=21){
			//add each card value from player hand to total points with ace = 1
			card = this->inHand.lookIn(i);
			totPoints += card.value();
		}	
	}
	//return calculated points
	
	return totPoints;
}

