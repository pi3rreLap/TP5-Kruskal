#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include "arete.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>


class Graph
{
    int V;    //Nombre cotés

    std::list<int> m_sommets;
    std::vector<Arete*> Aretes;

    void ajoutArete(int v, int w, int poids);

public:
    Graph();

    void affichageSommets() const;
    void affichageAretes() const;
    bool triageAretesPoids(Arete* i, Arete* j);
    void Kruskal();
};


#endif // GRAPHE_H_INCLUDED
