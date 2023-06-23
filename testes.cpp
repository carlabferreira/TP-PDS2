#include "Buscador.hpp"
#include "Recupera.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  Buscador testeBuscador("./documentos/");
  vector<string> linha;
  string s;

  string teste = "vitor";
  cout << "testeBuscador: " << endl;
  cout << testeBuscador.acessarIndice("a")["a.txt"] << endl;

  // Leitura do teclado, inclui a linha inteira; armazena essa entrada 
  //como os índices do vetor linha
  cout << "Digite as palavras a serem buscadas (digite 'fim' para encerrar):" << endl;
  while (cin >> s) {
    if (s == "fim") {
      break;
    }
    linha.push_back(s);
  }

  // Chamada do construtor de Recupera e um loop for para teste de impressão de valores
  Recupera testeRecupera(linha);
  map<string, map<string, int>> mapa_t = testeRecupera.acessoMapa();
  for (const auto &outer_map_pair : mapa_t) {
    cout << outer_map_pair.first << " contém:" << endl;
    for (const auto &inner_map_pair : outer_map_pair.second) {
      cout << inner_map_pair.first << ": " << inner_map_pair.second << " ocorrência(s)" << endl;
    }
  }


  return 0;
}
