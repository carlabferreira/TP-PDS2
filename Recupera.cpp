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

// Método para retornar o mapa gerado, que é privado
map<string, map<string, int>> Recupera::acessoMapa()
{
    vector<string> documentos;
    map<string, int> ocorrencias;

    for (const auto& entrada : mapa_) {
        for (const auto& docEntry : entrada.second) {
            documentos.push_back(docEntry.first);
            ocorrencias[docEntry.first] += docEntry.second;
        }
    }

    map<string, int> relevancia;
    calcularRelevancia(documentos, relevancia);

    // Filtrar documentos com base nas palavras-chave
    vector<string> palavrasChave;
    for (const auto& entrada : mapa_) {
        palavrasChave.push_back(entrada.first);
    }

    vector<string> documentosFiltrados;
    for (const auto& documento : documentos) {
        bool contemTodasPalavras = true;
        for (const auto& palavra : palavrasChave) {
            if (mapa_[palavra].count(documento) == 0) {
                contemTodasPalavras = false;
                break;
            }
        }
        if (contemTodasPalavras) {
            documentosFiltrados.push_back(documento);
        }
    }

    // Ordenar os documentos filtrados com base na relevância e ordem lexicográfica
    map<int, vector<string>> documentosOrdenados;
    for (const auto& entrada : relevancia) {
        for (const auto& documento : documentosFiltrados) {
            if (documento == entrada.first) {
                documentosOrdenados[entrada.second].push_back(documento);
            }
        }
    }

    map<string, map<string, int>> resultado;
    for (const auto& entrada : documentosOrdenados) {
        for (const auto& documento : entrada.second) {
            resultado[documento] = mapa_[documento];
            resultado[documento]["ocorrencias"] = ocorrencias[documento];
        }
    }

    return resultado;
}
/// Método para calcular a relevância de cada documento em relação à consulta.
void Recupera::calcularRelevancia(const vector<string>& documentos, map<string, int>& relevancia)
{
    for (const string& documento : documentos) {
        int score = 0;
        for (const auto& entrada : mapa_) {
            if (entrada.second.count(documento) > 0) {
                // Aumenta o score com a quantidade de ocorrências da palavra no documento
                score += entrada.second.at(documento);
            }
        }
        relevancia[documento] = score;
    }
}