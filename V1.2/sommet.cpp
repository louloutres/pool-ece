#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"

Sommet::Sommet(std::string id,double x,double y):m_id{id},m_x{x},m_y{y}
{
}
void Sommet::ajouterVoisin(const Sommet*voisin){
    m_voisins.push_back(voisin);

}
 void Sommet::afficherData() const{
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
 }
void Sommet::afficherVoisins() const{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}

std::unordered_map<std::string,std::string> Sommet::parcoursBFS() const{
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"BFS a completer"<<std::endl;
    return l_pred;
}
std::unordered_map<std::string,std::string> Sommet::parcoursDFS() const{
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"DFS a completer"<<std::endl;
    return l_pred;
}
std::unordered_set<std::string> Sommet::rechercherCC() const{
    std::unordered_set<std::string> cc;
    std::cout<<"rechercherCC a coder"<<std::endl;
    return cc;
}
Sommet::~Sommet()
{
    //dtor
}
