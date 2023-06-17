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

  // Leitura do teclado, inclui a linha inteira; armazena essa entrada como os
  // índices dos vetores
  cout << "testeRecupera: " << endl;
  while (cin >> s) {
    linha.push_back(s);
  }
  Recupera testeRecupera(linha);
  map<string, map<string, int>> mapa_t = testeRecupera.acessoMapa();
  for (auto &outer_map_pair : mapa_t) {
    cout << outer_map_pair.first << " contém: " << endl;
    for (auto &inner_map_pair : outer_map_pair.second) {
      cout << inner_map_pair.first << ": " << inner_map_pair.second << endl;
    }
  }

  return 0;
}