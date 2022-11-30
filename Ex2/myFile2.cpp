/*Ex2 devoir4 CSI2772A*/


#include <iostream> 
#include "myFile2.h"

using namespace std;


int main() {
    SetInt a; 	// object creation
    int* tab;

    while (a.nbElem() < 5)
    {
        cout << "add an int element" << endl;
        int elem;
        cin >> elem;
        a.add(elem);

    }
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "remove 10 " << endl;
    a.remove(10);
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "a contains :" << a.nbElem() << " elements " << endl;
    tab = a.tabElem();
    cout << "Les elements de a sont :" << endl;
    for (int i =0; i<a.nbElem(); i++)
        cout << tab[i] << endl;
       
    return 0;
}

//constructor
SetInt::SetInt(int ntab[], int size) {
    this->size = size;
    this->elem = new int[size];

    int* table = this->elem;

    for (int i = 0; i < size; i++) {
        *(table + i) = ntab[i];
    }
}
//destructor
SetInt::~SetInt() {
    delete this->elem;
}


void SetInt::add(int n) {
    //traverse list to check if element is already there
    bool check=true;
    for (int i = 0; i < size; i++) {
        if (n == *(this->elem + i)) {
            check = false;
        }
    }

    if (check) {
        //take capture of size before increase
        int cs = this->size;

        //create new array with increased list size to copy old array to
        int* ntable = new int[++this->size];
        //copy elements
        for (int i = 0; i < cs; i++) {
            ntable[i] = this->elem[i];
        }
        //add new int at end of array
        ntable[cs] = n;
        this->elem = ntable;

    }
}

void SetInt::remove(int n) {

    //traverse list to check if element is already there
    bool check = true;
    for (int i = 0; i < size; i++) {
        if (n == *(this->elem + i)) {
            check = false;
        }
    }
    //checks to see if list is empty or item is not in list
    if (this->size == 0) {
        cout<< "error, list is empty" << endl;
        return ;
    }
    else if (check) {
        cout << "item was not in list"<<endl;
        return;
    }

    //decrease list size   
    this->size--;

    //create flag to point out if we have found int to remove
    bool flag = false;

    //copy all elements to itself until the desired int to remove is found, 
    //activate flag to skip it and copy every element after
    for (int i = 0; i < this->size; i++) {
        if (this->elem[i] == n) {
            flag = true;
        }
        if (!flag) {
            this->elem[i] = this->elem[i];
        }
        else {
            this->elem[i] = this->elem[i+1];
        }        
    }
}

bool SetInt::contains(int n) {
    //traverses entire table, compares every int to n 
    //returns true1 if found, false0 otherwise

    for (int i = 0; i < this->size; i++) {
        if ((n == this->elem[i])){
            return 1;
        }
    }
    return 0;
}


int SetInt::nbElem() {
  //return size of table
    return this->size;
}


int* SetInt::tabElem() {
    //checks to see if table is emtpy
    if (this->size == 0) {
        return NULL;
    }
//create array based off of current table size
    int* table = new int[this->size];
//copy all elements over to array
    for (int i = 0; i < this->size; i++) {

        table[i] = this->elem[i];

    }
    return table;
}

bool SetInt::containsIn(int n, int& p) {
    //traverses table and stop when pointer is at desired position, then compares the int value at that position
    //returns true if found at that position, false otherwise

    for (int i = 0; i < this->size; i++) {
        if ((i == p) && (n == this->elem[i])) {
            return 1;
        }
    }
    return 0;

}

