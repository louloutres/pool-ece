#include <iostream>
#include "graphe.h"

int main()
{
    graphe g{"graphe_1.txt"};
    std::map<int,std::string> chemin;
    chemin.insert({1,"2"});
    chemin.insert({5,"0"});
    chemin.insert({0,"1"});
    g.afficher();
    affichageChemin(chemin);
    return 0;
}
