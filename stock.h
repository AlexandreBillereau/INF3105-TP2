/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  
  Squelette de départ. Vous pouvez modifier ce fichier à votre guise.
  Vous n'êtes pas oubligés de l'utiliser.
*/
#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include "Ingredient.h"


class Recette {
public:
    std::vector<Ingredient*> ingredients;

    friend std::istream& operator >> (std::istream& is, Recette& recette);
};


class Stock
{
    ArbreAVL<Ingredient> stock;

public:
    Stock();

    void ajout(std::string nomingredient, std::string date, int nombre);

    void retrait(std::string nomingredient, int nombre);

    void affichage();

    std::string dateExpiration(const Recette& recette) const;

    bool realisable(const Recette& recette) const;

    bool utilisation(const Recette& recette);

};




#endif // STOCK_H