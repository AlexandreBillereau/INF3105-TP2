//
// Created by alexandre on 21-11-26.
//

#ifndef TP2_INGREDIENT_H
#define TP2_INGREDIENT_H
#include <ctime>
#include "string"
#include "vector"
#include "lib/arbremap.h"

class Ingredient {

    class Element{
    public:
        int quantite;
        std::string date;
        Element(int _quantite, std::string _date): quantite(_quantite), date(_date){}
        bool operator < (const Element& autre) const {
          return date < autre.date;
        };
    };

  public:
    std::string nom;

    void ajouter(int nombre, std::string date);
    int& quantite(){ return quantiteTotal;}
    bool retirer(int);

  private:
    ArbreAVL<Element> elements;
    int quantiteTotal;

  public:
    Ingredient( int, std::string, std::string );
    Ingredient( int, std::string );
    static bool contien(std::string &chaine, std::vector<Ingredient*>& recette);
    static int recherche(std::string &chaine, std::vector<Ingredient*>& recette);

    bool operator != (Ingredient& recette);
    bool operator == (Ingredient& autre);
    bool operator < (const Ingredient& autreEntree) const;
    bool operator < (Ingredient &autreEntree) const;
    friend std::ostream& operator<< (std::ostream& os, Ingredient& i);
};


#endif //TP2_INGREDIENT_H
