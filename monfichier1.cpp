#include <iostream>
#include <iomanip>
using namespace std;

int main()
{  //all values determined with sizeof(), and their respective variable types

    cout << "Taille en octets d'un caractere: " << sizeof(char) << endl;
    cout << "Taille en octets d'un entier: " << sizeof(int) << endl;
    cout << "Taille en octets d'un reel: " << sizeof(float) << endl;
    cout << "Taille en octets d'un double: " << sizeof(double) << endl;
    cout << "Taille en octets d'un entier court: " << sizeof(short) << endl;
    cout << "Taille en octets d'un entier non signe: " << sizeof(unsigned int) << endl;

    return 0;
}