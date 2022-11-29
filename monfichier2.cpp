/* Fonction principale main */
#include "monfichier2.h"

/*EXERCICE 2 A)

la fonction main commence un loop permanent (unless user quits) qui appel une fonction menu, attend sa reponse
et demontre le "case"approprie. 2 de ces "cases" appel des fonctions qui font des calculs et retourne une valeure numerique
tandis que le dernier case est pour quitter, et annonce le nombre d'utilisations*/


int main(void) {
	char choix;
	double nvolume = 0; //nombre de fois que la fonction volume a été lancee
	double nsurface = 0; //nombre de fois que la fonction surface a été lancee
	double rayon, hauteur;

	// to keep track of how many times the case was used
	int s = 0, v = 0;

	while (1)
	{
		choix = menu();
		switch (choix)
		{
		case '1': cout << "Calcul de la surface :" << endl;
			cout << "Donnez le rayon: ";
			cin >> rayon;
			nsurface = surface(rayon);

			//added surface answer and upped case count
			cout << "La surface est: "<< nsurface;
			s++;
			cout << "" << endl;

			break;

		case '2': cout << "Calcul du volume :" << endl;
			cout << "Donnez le rayon: ";
			cin >> rayon;
			cout << "Donnez la hauteur: ";
			cin >> hauteur;
			nvolume = volume(rayon, hauteur);

			//added volume answer and upped case count

			cout << "Le volume est: " << nvolume;
			v++;
			cout << "" << endl;

			break;

		case '3':cout << "Sortie du programme" << endl;
			cout << "La fonction volume a ete lancee " << v << " fois" << endl;
			cout << "La fonction surface a ete lancee " << s << " fois" << endl;
			exit(0);
		default: break;

		}
	}
}



char menu(void) {
	char choix;
	cout << endl;
	cout << "Que souhaitez-vous faire ?:" << endl;
	cout << "\t-Calculer la surface du disque de rayon (Tapez 1)" << endl;
	cout << "\t-Calculer le volume du cylindre de rayon et hauteur (Tapez 2)" << endl;
	cout << "\t-Quittez le programme (Tapez 3)" << endl;
	cout << "" << endl;
	cout << "Votre choix: ";
	cin >> choix;
	return(choix);
}


//called Pi variable from .h file and put it in surface formula
double surface(double const& ray) {
	extern const double Pi;
	
	return Pi * ray * ray;
}


//called Pi variable from .h file and put it in volume formula
double volume(double const& ray, double const& haut) {

	extern const double Pi;

	return Pi * ray * ray * haut;


}


