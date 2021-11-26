/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  
  Squelette de départ. Vous pouvez modifier ce fichier à votre guise.
  Vous n'êtes pas oubligés de l'utiliser.
*/

#include "stock.h"

void Stock::ajout(std::string nomingredient, std::string date, int nombre) {
  Ingredient i(nombre, nomingredient, date);
  ArbreAVL<Ingredient>::Iterateur iter = stock.rechercher(i);
  if(iter)
    stock[iter].ajouter(nombre, date);
  else
    stock.inserer(i);
}

void Stock::affichage() {
  ArbreAVL<Ingredient>::Iterateur iter = stock.debut();
  for(; iter; iter++ )
    std::cout << stock[iter] << std::endl;
  std::cout << ";" << std::endl;
}

void Stock::retrait(std::string nomingredient, int nombre) {
  Ingredient i(nombre, nomingredient);
  ArbreAVL<Ingredient>::Iterateur iter = stock.rechercher(i);

  if(stock[iter].retirer(nombre)){
    stock.enlever(stock[iter]);
  }
}

Stock::Stock() {

}


std::istream& operator >> (std::istream& is, Recette& recette){

    std::string chaine;
    int quantite;


    for(;;) {
        is >> chaine;
        if(chaine == ";")
            break;
        is >> quantite;

        if(!Ingredient::contien(chaine, recette.ingredients))
          recette.ingredients.push_back(new Ingredient(quantite, chaine));
        else{
          recette.ingredients[Ingredient::recherche(chaine, recette.ingredients)]->quantite() += quantite;
        }
    }

    return is;
}

