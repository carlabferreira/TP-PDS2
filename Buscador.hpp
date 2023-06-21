#pragma once

#include <iostream>
#include <map>

class Buscador {
    public:
        //Construtor
        Buscador(std::string Caminho);

        //Cria o índice com os elementos atuais da pasta ./documentos/
        void CriarIndice(std::string Caminho);

        std::map<std::string, int> acessarIndice(std::string indice);

    private:
        std::map<std::string, std::map<std::string, int>> indice_;
};
