#include "sommet.h"

Sommet::Sommet(std::string id,double x,double y):m_id{id},m_x{x},m_y{y}
{ }

void Sommet::ajouterVoisin(const Sommet* voisin)
{
    m_voisins.insert({voisin});
}

void Sommet::afficherData() const
{
    std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")";
}

void Sommet::afficherVoisins() const
{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v.second->afficherData();
        std::cout<<" poids: "<<v.first
                 <<std::endl;
    }
}

std::string Sommet::get_id() const
{
    return m_id;
}

int Sommet::get_degre() const
{
    return m_voisins.size();
}
