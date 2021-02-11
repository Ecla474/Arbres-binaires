// LIFAP6 - Automne 2017 - R. Chaine
#include <iostream>
#include <cstdio> 
#include "element.h"
using namespace std;

void affichageElement(const Elem & e)
{
  cout << e;
}

bool estInferieurElement(Elem e1, Elem e2) 
{ 
  return e1 < e2;
}

bool estSuperieurElement(Elem e1, Elem e2) 
{ 
  return e1 > e2; 
}

bool estSuperieurOuEgalElement(Elem e1, Elem e2) 
{ 
  return e1 >= e2; 
}

bool estEgalElement(Elem e1, Elem e2) 
{ 
  return e1 == e2; 
}