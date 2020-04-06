#include "graphe.h"

Graph::Graph()
{

    std::ifstream file("D:/coursECE/informatique/infoLangCpp/semestre4/tp5/graphe.txt");  //Ouverture


    double num1 = 0;
    double num2 = 0;
    double poids = 0;
    int compteur = 0;
    double taille = 0;

    if(file)
    {
      while(compteur < 3 + taille)
      {
        compteur++;
        if (compteur == 1){
            file >> num1;
            if (num1 == 0)
                std::cout << "graphe non oriente" << std::endl;
            else
                std::cout << "graphe oriente" << std::endl;
        }
        else if (compteur == 2)
            file >> this->V;

        else if (compteur == 3){
            file >> taille;
        }
        else
        {
            file >> num1;
            num1--;
            file >> num2;
            num2--;
            file >> poids;
            ajoutArete(num1, num2, poids);

            std::list<int>::iterator it;
            it = find (m_sommets.begin(), m_sommets.end(), num1);

            if (it == m_sommets.end()){
                m_sommets.push_back(num1);
            }

            it = find (m_sommets.begin(), m_sommets.end(), num2);

            if (it == m_sommets.end()){
                m_sommets.push_back(num2);
            }

        }
      }
    }

    else
    {
       std::cout << "ERREUR ouverture." << std::endl;
    }
}

void Graph::ajoutArete(int v, int w, int poids)
{
    arretes.push_back(new Arete (v, w, poids));
}

void Graph::affichageSommets() const
{
    std::cout << "\nListe des sommets (ordre d'apparition dans le file):" << std::endl;

    for (auto sommet : m_sommets)
        std::cout << sommet + 1 << "  ";

    std::cout << std::endl;
}

void Graph::affichageAretes() const
{
    std::cout << "\nListe des arretes :" << std::endl;
    for (auto arete : aretes)
    {
        std::cout << "Arete ";
        arete->affichage();
    }
}

bool Graph::triageAretesPoids(Arete* i, Arete* j)
{
    return (i->getPoidsAretes() < j-> getPoidsAretes());
}

void Graph::Kruskal()
{
    std::sort (Aretes.begin(), Aretes.end(), triageAretesPoids); // on tri par poids les aretes
    std::vector<int> sommets;
    std::vector<int> edges;
    std::vector<Arete*> AretesActuelles;
    int poidsTot = 0;

    for (int i = 0; i < 10; i++)
        sommets.push_back(i);

    std::cout << "Aretes selectionnees : " << std::endl;
    for (auto Arete : Aretes)
    {
        edges = Arete->getSommets();

        if (AretesActuelles.size() < V)
        {
        if (sommets[edges[0]] != sommets[edges[1]])
        {
        AretesActuelles.push_back(Arete);
        poidsTot += Arete->getPoidsAretes(); // calcul du poids total

            for (int i = 0; i < V; i++)
            {
                if (sommets[i] == sommets[edges[1]] && i != edges[1]){
                    sommets[i] = sommets[edges[0]];
                }

            }
            sommets[edges[1]] = sommets[edges[0]];
            arete->affichage();
        }
        }
    }
    std::cout << "poids total = " << poidsTot << std::endl;
}
