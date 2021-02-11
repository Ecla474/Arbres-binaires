#include <iostream>
#include "abr.h"
using namespace std;

abr::abr()
{ 
    racine = NULL;
    cout << "Constructeur par defaut crée" << endl;
}

abr::abr(const abr & a)
{  

    Noeud * fg = a.racine->fg;
    racine->fg = fg;

    Noeud * fd=a.racine->fd;
    a.racine->fd = fd;

    Elem info = a.racine->info;
    racine->info = info;

    cout << "Constructeur par copie crée" << endl;


}

abr::~abr()
{
    this->effacer(racine);
     cout << "Arbre détruit" << endl;
}

void abr::effacer(Noeud * & n)
{
    if (n != NULL)
    {
        effacer(n->fg);
        effacer(n->fd);
        delete n;
        n = NULL;
    }
       
}

abr& abr::operator=(const abr &a){

    Elem INFO=a.racine->info;
    racine->info= INFO;

    Noeud * FG=a.racine->fg;
    racine->fg= FG;

    Noeud * FD=a.racine->fd;
    racine->fd= FD;

    return *this;

}

Noeud* abr::rechercheElementNoeud(Noeud * n,  Elem e)
{
    if (n != NULL) {
        if (e == n->info) 
        { 
            cout << "La valeur " << e << " à été retrouvé" << endl;
            return n; 
        }
        else if (e < n->info) { return rechercheElementNoeud(n->fg, e); }
        else return rechercheElementNoeud (n->fd, e);
        
    }
    cout << "La valeur " << e << " n'à pas été retrouvé" << endl;
    return NULL;
}

Noeud* abr::recherche(Elem e)
{
    return rechercheElementNoeud(racine, e);
}



void abr::insererElementNoeud(Noeud * & n, Elem e)
{
    if (n == NULL) 
    {
        n = new Noeud;
        n->info = e;
        n->fg = NULL;
        n->fd = NULL;
        
    }

    else 

    {
        if(estInferieurElement(e, n->info)) insererElementNoeud(n->fg, e);
        else if (estSuperieurElement(e,n->info)) insererElementNoeud(n->fd, e);
    }


}


void abr::insertion(Elem e)
{
    cout << "On rentre dans la fonction insertion" << endl;
    insererElementNoeud(racine, e);
    cout << "On sort de la fonction insertion" << endl;


}




void abr::affInfixeNoeud(const Noeud * n) const// decalage en int 
{
    if (n != NULL)
    {
        affInfixeNoeud(n->fg);
        affichageElement(n->info);
        cout << " ";
        affInfixeNoeud(n->fd);
    }
    

}

void abr::affInfixe() const
{
    affInfixeNoeud(racine);
    cout << endl;
}
