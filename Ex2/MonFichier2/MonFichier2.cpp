/*MonFichier2.cpp : Ex2 Devoir2 CSI2772A*/

#include "monfichier2.h"
#include <algorithm>


int main() {
	int monTab[size_tab] = { 2,4,8,20,3,55,87,13,2,5 };

	cout << "Affichage du tableau non trie :" << endl;
	for (int i = 0;i < size_tab;i++) {
		cout << monTab[i] << endl;
	}
	trier(monTab, size_tab);
	cout << "\nAffichage du tableau trie :" << endl;
	for (int i = 0;i < size_tab;i++) {
		cout << monTab[i] << endl;
	}
}


void trier(int tab[], int size)
{
	//VOTRE CODE VIENT ICI

	int j, tmp;


	for (int i = 1; i < size; i++) {

		//selecting specific number from tab[] for reference
		tmp = tab[i];
		//to point to number previous to tmp
		j = i - 1;

		//traverses tab[] until a number smaller than tmp is found
		//all while shifting the table one spot to the right
		while (j >= 0 && tmp <= tab[j]) {
			tab[j + 1] = tab[j];
			j--;
		}
		// when a number smaller than the reference is found, it becomes the new reference
		tab[j + 1] = tmp;
		
	}
}
