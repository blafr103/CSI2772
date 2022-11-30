/*Ex2 - Devoir 3 CSI2772A*/

#include "myLinkedList.h"
#include <iostream>
#include <string>

using namespace std;
int number = 0; //number of elements in the linked  list
				 
int main()
{
	Evaluation* first = NULL;	//Pointer on the first element of the list,the list is empty, so initialization to NULL			
	int choice;			//choice for the menu

	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& nb)
{
	//VOTRE CODE VIENT ICI

	//create input variables
	int pos,grad;
	char stud[capacity];

	//ask user for insert position
	cout << "After which element you want to insert ? (0 for start): ";
	cin >> pos;

	//check that its within range
	if (pos < 0 || pos > nb ) {
		cout << "Error!" << endl;
		return NULL;
	}

	cout << " " << endl;
	cout << "	Entering the item from the chained list. "<<endl;
	cout << " " << endl;

	//ask user for student name
	cout << "Enter the student: ";
	cin >> stud;
	cin.clear(); 
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//ask user for grade
	cout << "Enter the grade: ";
	cin >> grad;


	Evaluation* newEval = new Evaluation();



	//move pointer to where user wants to input
	for (int i =0; i < pos; i++) {
		p = p->next;
	}

	//reorganize pointers with new element 
	newEval->next = p;
	p = newEval;


	//copy all of char input to element
	for (int i = 0; i < 19; i++) {
		newEval->student[i] = stud[i];
	}
	//add grade input to element
	newEval->grade = grad;

	
	//increment amount of elements in list
	number++;


	return newEval;

}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& nb)
{
	//VOTRE CODE VIENT ICI

	//create position variable
	int pos;

	//ask user for delete position
	cout << "What is the number of the element to delete?: ";
	cin >> pos;

	//check that its within range
	if (pos < 0 || pos > nb) {
		cout << "Error!" << endl;
		return NULL;
	}

	//move pointer to where user wants to delete
	for (int i = 0; i < pos-1; i++) {
		p = p->next;
	}

	p->next = p->next->next;
	p = p->next;



	number--;

}



/**
*display() Function *
**/
void display(Evaluation* p)
{
	//VOTRE CODE VIENT ICI

	//traverse the list
	while (p != NULL) {

		//print out all char of student name at current pointer position
		cout << "Student: ";
		for (int i = 0; i < 19; i++) {
			cout << p->student[i];
		}
		cout << "" << endl;

		//print out grade of student name at current pointer position
		cout << "Their grade: ";
		cout << p->grade << endl;

		cout << "" << endl;

		//advance pointer
		p = p->next;
	}
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	//VOTRE CODE VIENT ICI
	
	int a=0;

	//add all of the grades togther by traversing list
	for (int i = 0; i < nbre; i++) {
		a = a + p->grade;
		p = p->next;
	}
	
	//print that sum divided by the total number of students to attain class average
	cout << "The average of the class is: "<< a/ nbre << endl;

	//check to see if the class is passing
	if (a / nbre <= 50) {
		cout << "Uh oh. Class average is below 50% " << endl;
		return 0;
	}
	return 1;

}






