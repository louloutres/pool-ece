#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "sommet.h"

class graphe
{
    public:
        graphe(std::string);
        ~graphe();
        void afficher() const;
        int rechercher_afficherToutesCC() const;
        std::map<int,std::string> Dijkstra() const;
        void affichageChemin(const std::map<int,std::string> & chemin);
    private:
        std::unordered_map<std::string,Sommet*> m_sommets;
};

void affichageChemin(const std::map<int,std::string> & chemin);

#endif // GRAPHE_H_INCLUDED
