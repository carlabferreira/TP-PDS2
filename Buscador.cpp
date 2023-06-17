#include "Buscador.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>

using namespace std;

//Função para normalizar a string de acordo com as instruções no enunciado
string normalizar(string s){
    string aux;
    int j = 0;
    for (const char i : s)
    {
        if (i >= 65 && i <= 90)
        {
            aux.push_back(i+32);
        }
        if(i >= 97 && i <= 122)
        {
            aux.push_back(i);
        }
    }
    return aux;
}

//Construtor do objeto buscador (só inicializa o índice)
Buscador::Buscador(string caminho){
    this->CriarIndice(caminho);
};

//Cria um índice no diretório especificado pela string caminho
void Buscador::CriarIndice(string caminho){
    string chave;
    string arquivo;

    //Esse loop itera por todos os arquivos no diretório especificado por caminho e cria o índice
    //o índice é um declarado como sugerido pelo professor, como
    //std::map<std::string, std::map<std::string, int>> indice_;
    //no arquivo Buscador.hpp
    for (const auto& entry : filesystem::directory_iterator(caminho)) {
        if (is_regular_file(entry.path())) {
            
            ifstream f;
            f.open(entry.path(), ios::in);

            while (f >> chave)
            {
                chave = normalizar(chave);
                arquivo = entry.path();
                arquivo.erase(0, caminho.size()); //remove ./documentos/ da string do caminho, deixando apenas "arquivo.txt" ao inves de "./documentos/arquivo.txt"
                this->indice_[chave][arquivo]++; //nao inicializei nada como 0 antes dessa operacao, pode ser que isso seja uma ma ideia, mas ta funcionando ao que parece
            }
            f.close();
        }
    }
}
//Como indice_ é um membro privado da classe Buscador, precisamos de um getter para acessar os conteúdos dele
//Buscador::acessarIndice("palavra") retorna o map<string, int> relacionado à "palavra", onde o primeiro elemento é o nome de um arquivo em caminho e o segundo elemento é quantoas vezes "palavra" aparece nesse arquivo
map<string, int> Buscador::acessarIndice(string indice){
    return this->indice_[indice];
}