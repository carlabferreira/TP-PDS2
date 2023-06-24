#include <iostream>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#include "Recupera.hpp"
#include "Buscador.hpp"

using namespace std;

int main() {
  
  Buscador buscador_("./documentos/"); //pelo construtor chama Criar Indice
  
  string s;
  vector<string> frase_buscada;

  //parte que separa a frase completa em palavras em um vector
  //separa por espaço
  //usa o stringstream para funcionar tanto para arquivo como para no terminal, em teoria
  stringstream ss;
  string choice = "/n";
  ss << choice;
  vector <string> broken;

  string word;
  while(ss >> word){
      broken.push_back(word);
  }

  Recupera recupera_(frase_buscada);
  map<string, map<string, int>> mapa_t = recupera_.acessoMapa();
  for (auto &outer_map_pair : mapa_t) {
    cout << outer_map_pair.first << " contém: " << endl;
    for (auto &inner_map_pair : outer_map_pair.second) {
      cout << inner_map_pair.first << ": " << inner_map_pair.second << endl;
    }
  }
  //! olhar se o arquivo tem todas as palavras e não só uma delas (PRIMEIRA)

  return 0;
}
