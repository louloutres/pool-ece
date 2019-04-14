#include "graphe.h"

graphe::graphe(std::string nomFichier)
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
    unsigned int ponderation;
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extrémités
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        ifs>>ponderation; if(ifs.fail()) throw std::runtime_error("Probleme lecture ponderation");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second,ponderation);
    }
}

void graphe::afficher() const
{
    std::cout<<"graphe : "<<std::endl
             <<"  ordre : "<<m_sommets.size()<<std::endl;
    for (auto& it : m_sommets)
    {
        std::cout<<"  sommet :";
        it.second->afficherData();
        std::cout<<std::endl;
        it.second->afficherVoisins();
        std::cout<<std::endl;
    }
}

graphe::~graphe()
{}

std::map<int,std::string> graphe::Dijkstra() const
{
    std::map<int,std::string> chemin;

}

void affichageChemin(const std::map<int,std::string> & chemin)
{
    for (auto it = --chemin.end(); it != --chemin.begin(); --it)
    {
        std::cout<<" "<<it->second;
        if (it!= chemin.begin())
        {
            std::cout<<"<--";
        }
    }
    std::cout<<": longueur ";
    int somme=0;
    for (auto it = --chemin.end(); it != --chemin.begin(); --it)
    {
        somme+=it->first;
        std::cout<<it->first;
        if (it!= chemin.begin())
        {
            std::cout<<"+";
        }
    }
    std::cout<<"="<<somme;
}
