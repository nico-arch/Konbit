# Konbit Language Parser (En Construction)

## Description

Le **Konbit Language Parser** est un projet en développement qui vise à créer un parseur pour le langage de programmation Konbit. Ce langage, inspiré de C++ et du créole, est conçu pour offrir une syntaxe simple, orientée objet, et interopérable avec d'autres langages de programmation, notamment C++.

Le parseur analyse le code Konbit et le traduit en code C++ compilable. Le projet est encore en phase de construction et de nombreuses fonctionnalités sont en cours de développement.

## Fonctionnalités Actuelles

- **Analyse de la syntaxe de base** : Le parseur peut analyser les mots-clés Konbit (comme `si`, `klas`, `metod`) et les transformer en leur équivalent C++.
- **Gestion des classes et méthodes** : Le code Konbit utilisant des classes et des méthodes est traduit en code C++.
- **Transformation du code Konbit en C++** : Le code Konbit est converti en un fichier `.cpp` qui peut ensuite être compilé avec un compilateur C++ standard.

### Exemple de Traduction

#### Code Konbit
```konbit
enkli "iostream"

klas Animal {
    metod son() {
        retounen "Rawr";
    }
}
```

#### Code C++ Généré
```cpp
#include "iostream"

class Animal {
    void son() {
        return "Rawr";
    }
};
```

## Statut du Projet

Le projet est **en cours de construction**. Actuellement, seules les fonctionnalités de base sont implémentées :

- Analyse des mots-clés simples (classes, méthodes, retours).
- Transformation des classes Konbit en classes C++.
- Génération de fichiers `.cpp` à partir du code Konbit.

### Prochaines Étapes

- Ajouter la gestion des variables, des boucles, et des conditions.
- Améliorer la gestion des erreurs et des blocs de code.
- Optimiser la performance de l'analyse des lignes de code.
- Ajouter une gestion plus avancée des types de données.

## Installation et Compilation avec Code::Blocks 20.03 (MINGW)

### Prérequis

- **Code::Blocks 20.03** avec **MINGW** installé.

### Instructions pour Code::Blocks

1. **Télécharger et installer Code::Blocks** :
   Si ce n'est pas déjà fait, téléchargez [Code::Blocks 20.03 avec MINGW]([https://www.codeblocks.org/downloads/26](https://www.codeblocks.org/downloads/binaries/)).

2. **Cloner le dépôt** :
   Cloner ou télécharger le projet dans votre environnement de travail :
   ```bash
   gh repo clone nico-arch/Konbit
   ```

3. **Créer un nouveau projet dans Code::Blocks** :
   - Ouvrez **Code::Blocks**.
   - Créez un nouveau projet **Console Application** en C++.
   - Ajoutez les fichiers `main.cpp`, `parser.cpp`, et `parser.h` à votre projet.

4. **Configurer le projet** :
   - Assurez-vous que **MINGW** est configuré correctement dans **Code::Blocks** :
     - Allez dans **Settings > Compiler...**
     - Sélectionnez le compilateur **GNU GCC Compiler**.
     - Assurez-vous que les chemins de **MINGW** sont bien configurés dans l'onglet **Toolchain executables**.

5. **Compiler et exécuter** :
   - Cliquez sur **Build and Run** pour compiler et exécuter le projet.
   - Le programme analysera le fichier Konbit (`test.kbt`) et générera un fichier C++ (`output.cpp`).

### Exemple avec Code::Blocks
1. Créez un fichier `test.kbt` contenant du code Konbit.
2. Ajoutez ce fichier à votre projet dans **Code::Blocks**.
3. Exécutez le projet pour analyser le fichier et générer le fichier C++.

### Structure du Projet

```bash
├── README.md
├── main.cpp            # Point d'entrée du programme
├── parser.cpp          # Implémentation du parseur
├── parser.h            # Déclarations du parseur
├── test.kbt            # Exemple de fichier Konbit à analyser
└── output.cpp          # Code C++ généré par le parseur
```

## Contributions

Le projet étant en cours de développement, toutes les suggestions et contributions sont les bienvenues. Si vous avez des idées, des améliorations ou souhaitez ajouter des fonctionnalités, n'hésitez pas à ouvrir une issue ou soumettre une pull request.

## Licence

Le projet est sous licence MIT. Vous êtes libre de l'utiliser, de le modifier et de le distribuer sous les termes de la licence.
