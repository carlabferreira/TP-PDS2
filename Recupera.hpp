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
    
    // Supõe que o map ajá está definido, tenho que lidar com a excessão caso não esteja
    map<string, map<string, int>> acessoMapa();

    // Mapa com a relação entre as palavras digitadas (chave) e os arquivos/quantidade de vezes (valor)
    private:
        map<string, map<string, int>> mapa_;
};

