#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <unordered_map>  // Inclusion de la bibliothèque pour unordered_map
#include <vector>

class Parser
{
    public:
        Parser(const std::string& cheminFichier); // Constructeur
        virtual ~Parser();

        void analyser();  // Méthode pour démarrer l'analyse du fichier
        std::string genererCodeCpp();  // Génère le code C++ à partir du code Konbit
        void sauvegarderCodeCpp(const std::string& fichierCpp);  // Sauvegarde le code C++ dans un fichier


    protected:

    private:
        std::string cheminFichier;  // Chemin vers le fichier .kbt
        std::unordered_map<std::string, std::string> tableSymboles;  // Table de symboles
        std::vector<std::string> codeCpp;  // Contiendra le code C++ généré

        void lireFichier();         // Méthode pour lire le fichier
        void analyserLigne(const std::string& ligne);  // Méthode pour analyser chaque ligne
        void initialiserTableSymboles();
        void ajouterCode(const std::string& code);  // Ajoute une ligne au code C++
};

#endif // PARSER_H
