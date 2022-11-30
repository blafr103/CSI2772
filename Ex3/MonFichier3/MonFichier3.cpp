/*MonFichier3.cpp : Ex3 Devoir2 CSI2772A*/

#include <iostream>
using namespace std;

int** triangleInf(int n)
{
	//VOTRE VIENT ICI

	//declare 2d array with double pointers
	int** matrix = { 0 };
	matrix = new int*[n];

	for (int i = 0; i <= n-1; i++) {

		//declare each 1d array lines of 2d array 
		matrix[i] = new int[n];

		for (int j = 0; j <= n-1; j++) {


			//if the we are looking at left edge of matrix, or at the end of the line,
			//a 1 is placed
			if (j == i || j == 0) {
				matrix[i][j] = 1;

			}
			
			//fills the rest of the triangle with values determined by defined pascal properties
			else if(0<j<i){
				matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
			}
		}
	}
	
	return matrix;
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}