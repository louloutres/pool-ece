#include "arrete.h"

Arrete::Arrete(std::string id,float poids1,float poids2,std::string id1,std::string id2):m_id{id},m_poids1{x},m_poids2{y},m_id1{id1},m_id2{id2}
{
    m_bouts.insert({m_id1,m_id2})
    m_poids.insert({m_poids1,m_poids2)
}
