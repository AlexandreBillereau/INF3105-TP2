/* Squelette pour classe générique ArbreMap<K, V>.
 * Lab8 -- Dictionnaires et Arbres binaires de recherche
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://CRIA2.uqam.ca/INF3105/lab8/
 *
 */
#if !defined(__ARBREMAP_H__)
#define __ARBREMAP_H__
#include "arbreAvl.h"


template <class K, class V>
class ArbreMap {

  class Entree{
  public:
    Entree(const K& _cle): cle(_cle) {}
    K cle;
    V valeur;

    bool operator < (const Entree& autreEntree) const {
      return cle < autreEntree.cle;
    }
  };

  public:

    class Iterateur {
      public:
        Iterateur(ArbreMap& a) : iter(a.entrees.debut()) {}
        Iterateur(typename ArbreAVL<Entree>::Iterateur i) : iter(i) {}
        operator bool() const {return iter.operator bool();};
        Iterateur& operator++() {++iter; return *this;}
        const K& cle() const {return (*iter).cle;}
        V& valeur() {return (V&) (*iter).valeur;}
      private:
        typename ArbreAVL<Entree>::Iterateur iter;
    };

    Iterateur debut() { return Iterateur(*this); }
    Iterateur fin() { return Iterateur(entrees.fin());}
    Iterateur rechercher(const K& cle) { return Iterateur(entrees.rechercher(cle));}
    Iterateur rechercherEgalOuSuivant(const K& cle) {return Iterateur(entrees.rechercherEgalOuSuivant(cle));}
    Iterateur rechercherEgalOuPrecedent(const K& cle) {return Iterateur(entrees.rechercherEgalOuPrecedent(cle));}

    bool contient(const K&) const;
    void enlever(const K&);
    void vider();
    bool vide() const;
    void afficher(ArbreMap<std::string,std::string>& dictionnaire);

    const V& operator[] (const K&) const;
    V& operator[] (const K&);

  private:
    // À compléter : voir la Section 8.11 (Arbres associatifs (Mapping Trees)) des notes de cours.

    ArbreAVL<Entree> entrees;
};

template <class K, class V>
void ArbreMap<K,V>::vider(){
     entrees.vider();
}

template <class K, class V>
bool ArbreMap<K,V>::vide() const{
  return entrees.vide();
}

template <class K, class V>
void ArbreMap<K,V>::enlever(const K& c)
{
    Entree entree(c);

    return entrees.enlever(entrees);
}

template <class K, class V>
bool ArbreMap<K,V>::contient(const K& c) const
{
    Entree entree(c);

    return entrees.contient(entree);
}

template<class K, class V>
void ArbreMap<K,V>::afficher(ArbreMap<std::string, std::string>& dictionnaire) {
  ArbreMap<std::string,std::string>::Iterateur iter = dictionnaire.debut();
  for(;iter;++iter){
    std::cout << iter.cle() << ":" << iter.valeur() << std::endl;
  }
}

template <class K, class V>
const V& ArbreMap<K,V>::operator[] (const K& c)  const
{
  typename ArbreAVL<Entree>::Iterateur iter = entrees.rechercher(c);
  if(!iter){
    entrees.inserer(Entree(c));
    iter = entrees.rechercher(c);
  }
  return entrees[iter].valeur;
}

template <class K, class V>
V& ArbreMap<K,V>::operator[] (const K& c) 
{
    typename ArbreAVL<Entree>::Iterateur iter = entrees.rechercher(c);
    if(!iter){
      entrees.inserer(Entree(c));
      iter = entrees.rechercher(c);
    }
    return entrees[iter].valeur;

}


#endif
