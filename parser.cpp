#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>

Parser::Parser(const std::string& cheminFichier) : cheminFichier(cheminFichier) {
std::cout << "Fichier à analyser : " << cheminFichier << std::endl;
initialiserTableSymboles();
}

Parser::~Parser()
{
    //dtor
}

void Parser::initialiserTableSymboles() {
    // Ajout des mots-clés du langage Konbit
    // Ajout des mots-clés Konbit et leur équivalent en C++
    tableSymboles["si"] = "if";
    tableSymboles["sinon"] = "else";
    tableSymboles["pandan"] = "while";
    tableSymboles["chak"] = "for";
    tableSymboles["klas"] = "class";
    tableSymboles["metod"] = "void";  // Pour simplifier, traduit en "void"
    tableSymboles["retounen"] = "return";
    tableSymboles["fonksyon"] = "void";  // Traduction simple pour les fonctions sans type
    tableSymboles["enkli"] = "#include";

    // Optionnel : Ajout direct des accolades, même si elles sont traitées en dehors de la table
    //tableSymboles["{"] = "{";
    //tableSymboles["}"] = "}";
    // etc.
}

// Méthode pour démarrer l'analyse
void Parser::analyser() {
    lireFichier();
}


// Méthode privée pour lire le fichier
void Parser::lireFichier() {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        return;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        analyserLigne(ligne);  // Analyse chaque ligne
    }

    fichier.close();
}

// Analyse chaque ligne et traduit les mots-clés Konbit en C++
void Parser::analyserLigne(const std::string& ligne) {
    std::string ligneCpp = ligne;
    size_t pos = 0;

    // Boucle tant qu'il reste des mots-clés ou symboles à analyser dans la ligne
    while (pos < ligneCpp.length()) {
        bool found = false;
        // Recherche de tous les mots-clés dans la table des symboles
        for (const auto& symbole : tableSymboles) {
            size_t foundPos = ligneCpp.find(symbole.first, pos);
            if (foundPos != std::string::npos) {
                // Remplace le mot-clé Konbit par son équivalent C++
                ligneCpp.replace(foundPos, symbole.first.length(), symbole.second);
                pos = foundPos + symbole.second.length();
                found = true;
                break;  // Continue à analyser la suite de la ligne
            }
        }

        if (!found) {
            pos++;  // Avance d'un caractère si aucun symbole n'est trouvé à cette position
        }
    }

    ajouterCode(ligneCpp);  // Ajoute la ligne complète traduite en C++
}

// Ajoute le code traduit en C++ dans le vecteur codeCpp
void Parser::ajouterCode(const std::string& code) {
    codeCpp.push_back(code);
}

// Génère le code C++ final à partir du code Konbit
std::string Parser::genererCodeCpp() {
    std::string codeComplet;
    for (const auto& ligne : codeCpp) {
        std::cout << ligne << std::endl;
        codeComplet += ligne + "\n";
    }
    return codeComplet;
}

// Sauvegarde le code C++ généré dans un fichier .cpp
void Parser::sauvegarderCodeCpp(const std::string& fichierCpp) {
    std::ofstream fichier(fichierCpp);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << fichierCpp << std::endl;
        return;
    }
    fichier << genererCodeCpp();
    fichier.close();
}
