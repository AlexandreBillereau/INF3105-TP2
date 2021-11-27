/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  
  Squelette de départ. Vous pouvez modifier ce fichier à votre guise.
  Vous n'êtes pas oubligés de l'utiliser.
*/

#include <fstream>
#include "stock.h"
#include "stock.cpp"

const int UTILISATION_CODE_FALSE = 0;
const int UTILISATION_CODE_TRUE = 1;

int main(int argc, const char** argv) {
    std::istream* entree;
    std::ifstream* entree_fichier = NULL;

    if(argc>1){
        entree = entree_fichier = new std::ifstream(argv[1]);
        if(entree->fail())
            std::cerr << "Erreur d'ouverture du fichier '" << argv[1] << "'" << std::endl;
    } else {
        entree = &std::cin;
    }

    Stock stock;
    ArbreMap<std::string, Recette> recettes;

    while(*entree){
        std::string commande;
        *entree >> commande;
        if(!(*entree)) break;
        if(commande=="recette"){
            std::string nomrecette;
            *entree >> nomrecette;
            Recette* recette = new Recette();
            *entree >> *recette;

            recettes[nomrecette] = *recette;

        } else if(commande=="ajout") {
            std::string nomingredient;
            *entree >> nomingredient;
            int nombre = 0;
            *entree >> nombre;
            if( nombre <= 0) {
                std::cerr << "Erreur sur le nombre d'ingredient." << std::endl;
                return -1;
            }
            std::string date;
            *entree >> date;

            stock.ajout(nomingredient, date, nombre);

        } else if(commande=="retrait") {

            std::string nomingredient;
            *entree >> nomingredient;
            std::cerr << "retrait " << nomingredient << std::endl;
            int nombre = 0;
            *entree >> nombre;
            if( nombre <= 0) {
                std::cerr << "Erreur sur le nombre d'ingredient." << std::endl;
                return -1;
            }

            stock.retrait(nomingredient, nombre);

        } else if(commande=="recommendation") {

            std::cout << "recommendation" << std::endl;

        } else if(commande=="utilisation") {
            std::string nomrecette;
            *entree >> nomrecette;

            if(recettes.contient(nomrecette)){
              bool toutLesIngredient = true;
              for(Ingredient *ingrediant : recettes[nomrecette].ingredients){
                if(!stock.contiens(ingrediant->nom, ingrediant->quantite())){
                  toutLesIngredient = false;
                  std::cout << nomrecette << " : " << UTILISATION_CODE_FALSE << std::endl;
                  break;
                }
              }
              if(toutLesIngredient) {
                for (Ingredient *ingrediant: recettes[nomrecette].ingredients)
                  stock.retrait(ingrediant->nom, ingrediant->quantite());
                std::cout << nomrecette << " : " << UTILISATION_CODE_TRUE << std::endl;
              }
            }else{
              std::cout << nomrecette << " : " << UTILISATION_CODE_FALSE << std::endl;
            }

        } else if(commande=="affichage") {
            stock.affichage();
        } else {
            std::cerr << "commande \"" << commande << "\" non reconnue !" << std::endl;
        }
    }
    delete entree_fichier;


    return 0;
}