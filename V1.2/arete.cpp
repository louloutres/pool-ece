#include "arete.h"

Arete::Arete(std::string id,std::string id1, std::string id2,Sommet* Som1,Sommet*Som2 ):m_id{id},m_id1{id1},m_id2{id2},S1{Som1},S2{Som2}
{

}

void Arete::remplir_poids(float p1,float p2)
{
    m_poids1=p1;
    m_poids2=p2;
}




