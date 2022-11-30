/*Ex1a - Devoir 3 CSI2772A*/

#include <iostream>

using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];



/* testPair() function*/
bool testPair(const Hand& h)
{
	//VOTRE CODE VIENT ICI
	
	
	//compares the color suit (**as instructions demanded) of all the players cards in-hand, returns true if a pair is found, false otherwise
	for (int i=0; i<5 ; i++) {
		for (int j = 0; j < 5; j++) {

			if (h[i].color == h[j].color && j!=i) {

				return true;
			
			}
		}	
	}
	return false;
}


/*Example of main()*/
int main()
{
	Card game[32];
	//VOTRE CODE VIENT ICI

	//make an accessible array of the card faces

	Face faces[8] = { seven, eight, nine, ten, jack, queen, king, ace };

	//create deck in 4 sections (by color), and pair each color up with each face 

	for (int i = 0; i <4 ;i++) {
		if (i == 0) {
			for (int j = 0; j <= 7; j++) {
				game[j].color = club;
				game[j].face = faces[j];
			}

		}
		else if (i == 1) {
			for (int k = 0; k <= 7;k++) {
				game[k+8].color = diamond;
				game[k+8].face = faces[k];
			}

		}
		else if (i == 2) {
			for (int j = 0; j <= 7; j++) {
				game[j+16].color = spades;
				game[j+16].face = faces[j];
			}
		}
		else if (i == 3) {
			for (int j = 0; j <= 7; j++) {
				game[j+24].color = heart;
				game[j+24].face = faces[j];
			}
		}
	}

	//prints out all 32 cards in the deck, colors and faces being represented by enum types

	for (int t = 0; t <=31; t++) {
		cout <<  game[t].color<<", "<< game[t].face << endl;
	}



		
	//code to use testPair function

	bool testPair(const Hand&);
	Hand myHand = { {club,nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, ace} };
	cout << "\nI have at least: " << testPair(myHand) << " pair" << endl;
	return 0;
}



