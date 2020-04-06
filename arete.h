#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>

class Arete
{
    std::vector<int> sommets;
    int m_poids;

public:
    Arete(int s1, int s2, int poids);
    int getPoidsAretes();
    std::vector<int> getSommets();
    void affichage() const;
};

#endif // ARETE_H_INCLUDED
