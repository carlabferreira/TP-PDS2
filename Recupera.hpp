#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Buscador.hpp"

using namespace std;

class Recupera
{
    public:
    // Construtor de Recupera, tem um vetor com as palavras lidas do terminal como parâmetro
    Recupera(vector<string> entrada);
    
    // Supõe que o map já está definido, tenho que lidar com a excessão caso não esteja
    map<string, map<string, int>> acessoMapa();

    private:
        map<string, map<string, int>> mapa_;
};
