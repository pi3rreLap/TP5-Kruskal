#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include "arete.h"
#include "graphe.h"



int main()
{
    Graph g;

    g.affichageSommets();
    g.affichageAretes();
    g.Kruskal();

    return 0;
}
