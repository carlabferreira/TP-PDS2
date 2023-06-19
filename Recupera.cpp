#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Buscador.hpp"
#include "Recupera.hpp"

using namespace std;

// Construtor, o parâmetro é o vetor de string com a entrada de palavras
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

// Método para retornar o mapa gerado, que é privado
map<string, map<string, int>> Recupera::acessoMapa()
{
   vector<string> documentos;
    for (const auto& entrada : mapa_)
    {
        for (const auto& docEntry : entrada.second)
        {
            documentos.push_back(docEntry.first);
        }
    }

    map<string, int> relevancia;
    calcularRelevancia(documentos, relevancia);

    // Ordenar os documentos com base na relevância e ordem lexicográfica
    map<int, vector<string>> documentosOrdenados;
    for (const auto& entrada : relevancia)
    {
        documentosOrdenados[entrada.second].push_back(entrada.first);
    }

    map<string, map<string, int>> resultado;
    for (const auto& entrada : documentosOrdenados)
    {
        for (const string& documento : entrada.second)
        {
            resultado[documento] = mapa_[documento];
        }
    }

    return resultado;
}

// Método para calcular a relevância de cada documento em relação à consulta. 
void Recupera::calcularRelevancia(const vector<string>& documentos, map<string, int>& relevancia)
{
     for (const string& documento : documentos)
    {
        int score = 0;
        for (const auto& entrada : mapa_)
        {
            if (entrada.second.count(documento) > 0)
            {
                // Aumenta o score se a palavra estiver presente no documento
                  score += entrada.second.at(documento);
            }
        }
        relevancia[documento] = score;
    }
}