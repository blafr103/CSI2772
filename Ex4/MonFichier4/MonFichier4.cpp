/*MonFichier4.cpp : Ex4 Devoir2 CSI2772A*/

#include "MonFichier4.h"
#include <iostream> 

int main() {
	char* chaine[nb_ch];		//tableau de pointeurs sur caractere(s)
	char choix;			//variable pour le choix saisi dans menu()

	cout << endl << "Saisissez les 5 chaines de caracteres en les terminant par une tabulation et un retour chariot :" << endl;

	//had to change getline delimiter, remove ignore, and add clear to make function work
	//would not work otherwise for some reason

	for (int i = 0; i < nb_ch; i++) {
		chaine[i] = new char[size_ch];	//reservation de memoire pour une chaine
		cin.getline(chaine[i], size_ch, '\n');	//saisie de la chaine
		//cin.ignore(INT_MAX, '\n');		//on ignore les retours chariot
		cin.clear();
	}


	display(chaine, nb_ch);


	while (1) {
		choix = menu();

		switch (choix)
		{
		case '1':	display(chaine, nb_ch);
			break;
		case '2':	replace(chaine, nb_ch, size_ch);
			break;
		case '3':	trier(chaine, nb_ch);
			break;
		case '4':	exit(0);
		default:	break;
		}
	}
}





/********************************************************************************/
/* Fonction menu Fournie */
/********************************************************************************/
char menu(void)
{
	char choix;

	cout << endl << endl << "\t\tMenu" << endl << endl;
	cout << "1) Affichage des chaines de caracteres." << endl;
	cout << "2) Remplacement d'une chaine par une autre" << endl;
	cout << "3) Tri des chaines" << endl;
	cout << "4) Sortie du programme." << endl << endl;
	cout << "Votre choix :";
	cin >> choix;

	return(choix);

}

/********************************************************************************/
/*La fonction display qui affiche les chaines de caractères*/
/********************************************************************************/
void display(char* tab[], int const& nbre)

{
	//VOTRE VIENT ICI
	for (int i = 0; i <= nbre-1; i++) {
		cout << "La chaine " << i << " est : " << tab[i] << endl;
	}

}

/*************************************************************/
/*La fonction replace qui remplace une chaine par une autre*/
void replace(char* tab[], int const& nbre, int const& size)
{
	int numero;		//la chaine a modifier

	cout << endl << "Donnez le numero de la chaine a modifier: ";
	cin.ignore(INT_MAX, '\n');
	cin >> numero;

	//VOTRE VIENT ICI
}

/********************************************************************************/
/*La fonction trier qui trie les chaines */
/********************************************************************************/
void trier(char* tab[], int const& nbre)
{
	//VOTRE VIENT ICI


	for (int i = 1; i < nbre; i++) {

		
		int j = i ;

	
		while (j >= 0 && strcmp(tab[j-1], tab[j]) > 0 ) {
	




			j--;
		}		
	}
}

