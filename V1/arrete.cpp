#include "arrete.h"
/*
Arrete::Arrete(std::string id,float poids1,float poids2,std::string id1,std::string id2):m_id{id},m_poids1{x},m_poids2{y},m_id1{id1},m_id2{id2}
{

    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );

    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");

    std::string id;
    double x,y;
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture donn�es sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture donn�es sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture donn�es sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }

    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    std::string id_voisin;
    unsigned int ponderation;
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extr�mit�s
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        ifs>>ponderation; if(ifs.fail()) throw std::runtime_error("Probleme lecture ponderation");
        //ajouter chaque extr�mit� � la liste des voisins de l'autre (graphe non orient�)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second,ponderation);
    }
}
    m_bouts.insert({m_id1,m_id2})
    m_poids.insert({m_poids1,m_poids2)
}
*/
