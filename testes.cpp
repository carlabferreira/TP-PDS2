#include "Buscador.hpp"
#include "Recupera.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

//string normalizar(string s);

int main(int argc, char const *argv[]) {
  Buscador testeBuscador("./documentos/");
  vector<string> linha;
  string s;
  
  // string teste = "vitor"; //?
  
  /*cout << "testeBuscador: " << endl;
  cout << testeBuscador.acessarIndice("a")["a.txt"] << endl;*/

  /*
  while (cin >> s) { //rodando ate EOF ou erro
    frase_buscada.push_back(s);
    if (s == "pare"){
      break;
    }
  }*/
  
  //parte que separa a frase completa em palavras em um vector
  //separa por espaço
  //usa o stringstream para funcionar tanto para arquivo como para no terminal, em teoria
  string str;
  cin >> str;
  str = normalizar(str);
  stringstream ss(str);
  vector<string> v;
 
  while (getline(ss, s, ' ')) {
    v.push_back(s);
  }

  // Chamada do construtor de Recupera e um loop for para teste de impressão de valores
  Recupera testeRecupera(v);
  map<string, map<string, int>> mapa_t = testeRecupera.acessoMapa();
  for (auto& outer_map_pair : mapa_t) {
    cout << outer_map_pair.first << " contém: " << endl;
    for (auto& inner_map_pair : outer_map_pair.second) {
      //cout << "AAAAA" << endl; //teste para ver q não ta entrando no loop
      cout << inner_map_pair.first << ": " << inner_map_pair.second << endl; //inner_map_pair.second a relevancia
    }
  }

  return 0;
}
