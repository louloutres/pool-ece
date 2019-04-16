#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "sommet.h"

class Arete
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Arete(std::string,std::string,std::string,Sommet*,Sommet*);
        void remplir_poids(float,float);

        ~Arete();

    protected:

    private:
        float m_poids1;
        float m_poids2;
        /// Données spécifiques à l'arete
        std::string m_id; // Identifiant
        Sommet* S1;
        Sommet* S2;
        std::string m_id1,m_id2;// Position

};

#endif // ARETE_H_INCLUDED
