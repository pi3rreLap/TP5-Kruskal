#include "arete.h"

Arete::Arete(int s1, int s2, int poids)
{
    sommets.push_back(s1);
    sommets.push_back(s2);
    m_poids = poids;
}

void Arete::affichage() const
{
    std::cout << sommets[0] + 1 << "-" << sommets[1] + 1 << " : " << m_poids << std::endl;
}

int Arete::getPoidsAretes()
{
    return m_poids;
}

std::vector<int> Arete::getSommets()
{
    return sommets;
}
