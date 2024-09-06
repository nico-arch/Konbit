#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <unordered_map>  // Inclusion de la biblioth�que pour unordered_map
#include <vector>

class Parser
{
    public:
        Parser(const std::string& cheminFichier); // Constructeur
        virtual ~Parser();

        void analyser();  // M�thode pour d�marrer l'analyse du fichier
        std::string genererCodeCpp();  // G�n�re le code C++ � partir du code Konbit
        void sauvegarderCodeCpp(const std::string& fichierCpp);  // Sauvegarde le code C++ dans un fichier


    protected:

    private:
        std::string cheminFichier;  // Chemin vers le fichier .kbt
        std::unordered_map<std::string, std::string> tableSymboles;  // Table de symboles
        std::vector<std::string> codeCpp;  // Contiendra le code C++ g�n�r�

        void lireFichier();         // M�thode pour lire le fichier
        void analyserLigne(const std::string& ligne);  // M�thode pour analyser chaque ligne
        void initialiserTableSymboles();
        void ajouterCode(const std::string& code);  // Ajoute une ligne au code C++
};

#endif // PARSER_H
