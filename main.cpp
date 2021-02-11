#include <iostream>
#include "abr.h"
#include "perf.h"
using namespace std;

int main (void)
{
    const int nbAbr = 3;
    const int nbAbrMax = 10;
    abr a;
    cout << "Hello World !" << endl;
    abr();
    cout << "Arbre crée" << endl;
    a.insertion(2);
    a.insertion(5);
    a.insertion(1);
    a.insertion(4);
    a.recherche(3);
    a.recherche(5);
    a.affInfixe();
 // abr b (a);
/*  b.insertion(6);
    b.affInfixe();
    */

    performanceInsertArbre(nbAbrMax, nbAbr, 1);

    return 0;
}