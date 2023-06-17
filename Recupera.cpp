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

    // Leitura do teclado, inclui a linha inteira; armazena essa entrada como os índices dos vetores
    // Esse loop deveria estar no main e o vetor que ele gera deveria ser passado como parâmetro do construtor (?)
    //vector<string> linha;
    //string s;
    /*while(cin >> s)
    {
        linha.push_back(s);
    }*/

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