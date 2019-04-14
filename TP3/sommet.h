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

class Sommet
{
    public:
        Sommet(std::string,double,double);
        void ajouterVoisin(const Sommet*, unsigned int &ponderation);
        void afficherData() const;
        void afficherVoisins() const;
        std::string get_id() const;
        int get_degre() const;
        ~Sommet();
    private:
        std::unordered_map<unsigned int, const Sommet*> m_voisins;
        std::string m_id;
        double m_x, m_y;
};

#endif // SOMMET_H_INCLUDED
