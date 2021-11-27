//
// Created by alexandre on 21-11-26.
//

#include <iostream>
#include "Ingredient.h"

Ingredient::Ingredient(int _quantite, std::string _nom, std::string _date):
quantiteTotal(_quantite), nom(_nom){
  elements.inserer(Element(_quantite, _date));
}

Ingredient::Ingredient(int _quantite, std::string _nom): quantiteTotal(_quantite), nom(_nom) {}


bool Ingredient::contien(std::string &chaine, std::vector<Ingredient *> &recette) {
  if(!recette.size())
    return false;
  for (int i = 0; i < recette.size() - 1 ; ++i) {
    if(chaine == recette[i]->nom)
      return true;
  }
  return false;
}

int Ingredient::recherche(std::string &chaine, std::vector<Ingredient *> &recette) {
  for (int i = 0; i < recette.size() - 1 ; ++i) {
    if(chaine == recette[i]->nom)
      return i;
  }

  return -1;
}

bool Ingredient::operator!=(Ingredient &recette) {
  return nom != recette.nom;
}

bool Ingredient::operator<(const Ingredient &autreEntree) const {
  return nom < autreEntree.nom;
}

bool Ingredient::operator<(Ingredient &autreEntree) const{
  return nom < autreEntree.nom;
}

bool Ingredient::operator==(Ingredient &autre) {
  return nom == autre.nom;
}

void Ingredient::ajouter(int nombre, std::string date) {
  quantiteTotal += nombre;
  elements.inserer(Element(nombre, date));
}

std::ostream& operator<< (std::ostream& os, Ingredient &i) {
  return os << i.nom << " " << i.quantiteTotal;
}

bool Ingredient::retirer(int _quant) {
  ArbreAVL<Element>::Iterateur iter = elements.debut();
  int quant = _quant;

  while(quant){
    if(elements[iter].quantite - quant < 0 ){
      int temp = quant - elements[iter].quantite;
      quantiteTotal -= elements[iter].quantite;
      elements.enlever(elements[iter]);
      quant = temp;
    }
    else{
      elements[iter].quantite -= quant;
      quantiteTotal -= quant;
      if(quantiteTotal == 0){
        elements.enlever(elements[iter]);
        return true;
      }
      return false;
    }
    ++iter;
  }
}

Ingredient::Ingredient(std::string _nom) {
  nom = _nom;
}

