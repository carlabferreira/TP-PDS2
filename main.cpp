#include "Buscador.hpp"
#include "Recupera.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

struct comp
{
  template <typename T>

  // Função comparadora
  bool operator()(const T &l, const T &r) const
  {
    if (l.second != r.second)
    {
      return l.second > r.second;
    }
    return l.first < r.first; // se ocorrencia igual, não alterar. Já estão ordenados lexicograficamente no recupera
  }
};

// Função para ordenar o map de acordo com o número de palavras encontradas em cada um dos arquivos.
void sort(map<string, int> &M)
{

  // Declara um set de pares e insere pares de acordo com a função comparadora comp().
  set<pair<string, int>, comp> S(M.begin(), M.end());

  // Printa o novo map já ordenado
  for (auto &it : S)
  {
    // cout << it.first << ' ' << it.second << endl;
    cout << it.first << endl; // pra printar so o nome do arquiv
  }
}

int main(int argc, char const *argv[])
{
  Buscador Buscador_("./documentos/"); // cria o indice
  vector<string> palavra;
  string linha;

  cout << "Se entrada for no terminal, aperte enter para enviar a frase e Ctrl+Z para parar a execução" << endl;
  cout << "Se entrada for um arquivo, pegará cada linha como frase e irá até o final" << endl << endl;
  //------------------------------------
  while (getline(cin, linha))
  { // em arquivos, para no fim

    // parte que separa a frase completa em palavras em um vector
    // separa por espaço
    // usa o stringstream para funcionar tanto para arquivo como para no terminal, em teoria
    istringstream iss(linha);
    while (iss >> linha)
    {
      palavra.push_back(normalizar(linha));
    }

    //------------------------------------
    // Chamada do construtor de Recupera e um loop for para teste de impressão de valores e construção do mapa simples
    Recupera Recupera_(palavra);
    map<string, map<string, int>> mapa_t = Recupera_.acessoMapa();
    map<string, int> mapa_aux;
    for (const auto &outer_map_pair : mapa_t)
    {
      // cout << outer_map_pair.first << " contém: ";
      for (const auto &inner_map_pair : outer_map_pair.second)
      {
        // cout << inner_map_pair.second << " ocorrência(s)" << endl;
        // copiando o arquivo e a ocorrencia para um mapa auxiliar simples
        mapa_aux.insert(make_pair(outer_map_pair.first, inner_map_pair.second));
      }
    }

    //------------------------------------
    // Ordenar o que tem mais ocorrencias primeiro, já ordenado lexicograficamente no recupera
    sort(mapa_aux);

    mapa_aux.clear();
    mapa_t.clear();
    palavra.clear();
    cout << endl;

    // getline(cin, linha);
  }
  // while (linha != "pare" || linha[0] == EOF);
  return 0;
}