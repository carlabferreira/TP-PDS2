#include "Buscador.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    Buscador testeBuscador("./documentos/");



    string teste = "vitor";
    cout << testeBuscador.acessarIndice("a")["a.txt"] << endl;
    return 0;
}
