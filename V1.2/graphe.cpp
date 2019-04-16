#include <fstream>
#include <iostream>
#include "graphe.h"

graphe::graphe(std::string nomFichier,std::string nomFichier1){
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id,ida;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    Sommet* S;
    Sommet* S1;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémité
        ifs>>ida;if(ifs.fail()) throw std::runtime_error("Probleme lecture id  arete");
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        S=m_sommets.find(id)->second;
        S1=m_sommets.find(id_voisin)->second;
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
        m_arete.insert({ida,new Arete{ida,id,id_voisin,S,S1}});


    }
    std::ifstream ifs1{nomFichier1};
    if (!ifs1)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier1 );
    ifs1 >> taille;
    if ( ifs1.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int nbrpoid;
    ifs1>>nbrpoid;
    float p1,p2;
    //lecture des pondérations
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémité
        ifs1>>id;if(ifs1.fail()) throw std::runtime_error("Probleme lecture id  arete");
        ifs1>>p1; if(ifs1.fail()) throw std::runtime_error("Probleme lecture arete poids 1");
        ifs1>>p2; if(ifs1.fail()) throw std::runtime_error("Probleme lecture arete poids 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_arete.find(id))->second->remplir_poids(p1,p2);

    }

}
void graphe::afficher() const{
    std::cout<<"graphe : "<<std::endl;
    std::cout<<"  coder l'affichage ! "<<std::endl;
}

void graphe::parcoursBFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    l_pred=s0->parcoursBFS();
}
void graphe::afficherBFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"parcoursBFS a partir de "<<id<<" :"<<std::endl;
    l_pred=s0->parcoursBFS();
    for(auto s:l_pred){
        std::cout<<s.first<<" <--- ";
        std::pair<std::string,std::string> pred=s;
        while(pred.second!=id){
            pred=*l_pred.find(pred.second);
            std::cout<<pred.first<<" <--- ";
        }
        std::cout<<id<<std::endl;
    }
}
void graphe::parcoursDFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    l_pred=s0->parcoursDFS();
}
void graphe::afficherDFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"parcoursDFS a partir de "<<id<<" :"<<std::endl;
    l_pred=s0->parcoursDFS();
    for(auto s:l_pred){
        std::cout<<s.first<<" <--- ";
        std::pair<std::string,std::string> pred=s;
        while(pred.second!=id){
            pred=*l_pred.find(pred.second);
            std::cout<<pred.first<<" <--- ";
        }
        std::cout<<id<<std::endl;
    }
}
int graphe::rechercher_afficherToutesCC() const{
    int i=0;
    std::cout<<"composantes connexes :"<<std::endl;
    std::cout<<"recherche et affichage de toutes les composantes connexes a coder"<<std::endl;
    return i;
}
graphe::~graphe()
{
    //dtor
}
