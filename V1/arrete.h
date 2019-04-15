#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include "sommet.h"

class Arrete
{
public:
    Arrete(std::string,float,float);
    ~Arrete();
private:
    float m_poids1;
    float m_poids2;
    std::string id1;
    std::string id2;
    std::unordered_map<float,float>m_poids;
    std::unordered_map<std::string,std::string>m_bouts;
    std::string m_id;
    std::unordered_map<std::string,Sommet*> m_sommet;
};


#endif // ARRETE_H_INCLUDED
