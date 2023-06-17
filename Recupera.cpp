#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Buscador.hpp"
#include "Recupera.hpp"

using namespace std;

Recupera::Recupera(vector<string> entrada)
{
    Buscador pastaBuscador("./documentos");

    // Para cada chave string do mapa(índices do vetor), o método acessarIndice
    // é chamado e retorna o map correspondente (arquivos, quantidade de vezes)

    for (int i = 0; i < entrada.size(); i++)
    {
       mapa_[entrada[i]] = pastaBuscador.acessarIndice(entrada[i]);
    }

}

map<string, map<string, int>> Recupera::acessoMapa()
{
    return this->mapa_;
}