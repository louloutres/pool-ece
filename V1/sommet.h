#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include "arrete.h"

class Sommet
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Sommet(std::string,double,double);
        void ajouterVoisin(const Sommet*);
        void afficherData() const;
        void afficherVoisins() const;
        int getDegre()const;
        std::vector<const Sommet*> donner_voisins() const;
         std::string donner_id() const;
        ///m�thode de parcours en largeur du graphe � partir du sommet
        ///renvoie les pr�d�cesseurs sous forme d'une map (cl�=id du sommet,valeur=id de son pr�d�cesseur)
        std::unordered_map<std::string,std::string> parcoursBFS(std::unordered_map<std::string,Sommet*> mapsommets) const;
         ///m�thode de parcours en profondeur du graphe � partir du sommet
        std::unordered_map<std::string,std::string> parcoursDFS(std::unordered_map<std::string,Sommet*> mapsommets) const;

        ///m�thode qui recherche la composante connexe du sommet
        ///renvoie la liste des ids des sommets de la composante
        std::unordered_set<std::string> rechercherCC(std::unordered_map<std::string,Sommet*> mapsommets) const;
        ~Sommet();

    protected:

    private:
        /// Voisinage : liste d'adjacence
        std::vector<const Sommet*> m_voisins;

        /// Donn�es sp�cifiques du sommet
        std::string m_id; // Identifiant
        double m_x, m_y; // Position

};

#endif // SOMMET_H
