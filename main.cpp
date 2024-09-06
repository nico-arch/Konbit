#include "parser.h"
#include <iostream>

int main() {
    // Instancie le parseur avec le chemin du fichier .kbt
    Parser parser("test.kbt");

    // Analyse le fichier Konbit
    parser.analyser();

    // Sauvegarde le code C++ généré dans un fichier .cpp
    parser.sauvegarderCodeCpp("output.cpp");

    std::cout << "Analyse terminee et code C++ genere dans 'output.cpp'." << std::endl;

    return 0;
}
