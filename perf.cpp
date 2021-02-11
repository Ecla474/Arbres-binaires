#include "perf.h"
#include "abr.h"
#include <chrono>
#include <fstream>
using namespace std;

void performanceInsertArbre (int nbAbrMax, int nbAbr, int a)
{
    ofstream fichier;
    fichier.open("perfomances_arbres.txt");

    abr * chrono[nbAbr];

    for (int i = 0; i < nbAbr; i++)
    {
        chrono[i] = new abr ();
    }

    for (int j = a; j <= nbAbrMax; j += a)
    {
        chrono::time_point<chrono::system_clock> depart, arrive;
        

        for (int i = 0; i < nbAbr; i++)
        {
            chrono[i]->insertion(i);
        }

        depart = chrono::system_clock::now();

        for (int l = 0; l < nbAbr; l++)
        {
           chrono[l]->recherche(l);
        }

        arrive = chrono::system_clock::now();

        chrono::duration<double> tempsMicrosecondes = arrive - depart;

        fichier << j << " " << tempsMicrosecondes.count() / nbAbr << endl;

        for (int m = 0; m < nbAbr; m++)
        {
            for (int n = 0; n < a - 1; n++)
            {
                chrono[m]->insertion(m);
            }
        }
    }
        
        for (int o = 0; o < nbAbr; o++)
        {
            delete chrono[o];
        }

        fichier.close();
        
        
    
}