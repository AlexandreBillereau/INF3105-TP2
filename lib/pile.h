/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
*/

#if !defined(__PILE_H__)
#define __PILE_H__

template <class T>
class Pile
{
public:
    Pile();
    ~Pile();

    void empiler(const T&);

    void depiler(T& out);  // Depiler et copier le sommet dans out.
    T depiler();

    bool vide() const;
    void vider();
    Pile<T>& operator = (const Pile<T>& autre);

private:

    class Cellule
    {
    public:
        Cellule(const T& e, Cellule* c);
        T contenu;
        Cellule* suivante;
    };

    Cellule* sommet;
};


#include "assert.h"

template <class T>
Pile<T>::Pile()
{
    sommet = nullptr;
}


template <class T>
Pile<T>::~Pile()
{
    vider();
}

template <class T>
bool Pile<T>::vide() const {
    return sommet == nullptr;
}

template <class T>
void Pile<T>::vider()
{
    while(!vide())
        depiler();
}

template <class T>
Pile<T>::Cellule::Cellule(const T& e, Cellule* c)
        : suivante(c)
{
    contenu=e;
}

template <class T>
void Pile<T>::empiler(const T& e)
{
    sommet = new Cellule(e, sommet);
    assert(sommet);
}

template <class T>
T Pile<T>::depiler()
{
    assert(sommet);
    T element = sommet->contenu;
    Cellule *anciensomet = sommet;
    sommet = sommet->suivante;
    delete anciensomet;
    return element;
}

template <class T>
void Pile<T>::depiler(T& e)
{
    assert(sommet!=nullptr);
    e = sommet->contenu;
    Cellule* c = sommet;
    sommet = sommet->suivante;
    delete c;
}

template <class T>
Pile<T>& Pile<T>::operator = (const Pile<T>& autre){
    if(this==&autre) return *this;
    vider();
    if(autre.sommet!=nullptr){
        sommet = new Cellule(autre.sommet->contenu, nullptr);
        Cellule *cp = autre.sommet;
        Cellule *c = sommet;
        while(cp->suivante!=nullptr){
            c->suivante = new Cellule(cp->suivante->contenu, nullptr);
            c = c->suivante;
            cp = cp->suivante;
        }
    }
    return *this;
}


#endif
