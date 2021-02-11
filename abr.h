#ifndef _ABR
#define _ABR
#include "element.h"

struct Noeud
{
    Elem info;
    Noeud * fg;
    Noeud * fd;
};



class abr

{

    private :

    Noeud* racine;

    void effacer(Noeud * & n);

    Noeud* rechercheElementNoeud(Noeud * n, Elem e);

    void insererElementNoeud(Noeud * & n, Elem e);

    void affInfixeNoeud(const Noeud * n) const;



    public :

    abr(); // Constructeur par defaut

    abr(const abr & a); // Constructeur par copie

    ~abr(); // Destructeur

    Noeud* recherche(Elem e);
    
    void insertion(Elem e);

    
    void affInfixe()const;

    abr& operator=(const abr &a);
    

};

#endif