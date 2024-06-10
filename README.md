# cpp08 - École 42 | Paris

## Description

Ce projet fait partie des exercices du module CPP08. Il a pour but de renforcer les compétences en programmation C++98, en mettant l'accent sur l'utilisation des containers de la STL, des itérateurs et des algorithmes en C++.

## Exercise 00: Easy find

L'objectif de l'exercice 00 consiste à créer une fonction template en C++. Vous allez développer une fonction capable de trouver un élément spécifique dans un container. La fonction à implémenter inclut :

- `easyfind`: Accepte un container de type T et un entier. Trouve la première occurrence de l'entier dans le container.

Cette fonction doit pouvoir être appelée avec n'importe quel type de container d'entiers. Si l'élément n'est pas trouvé, une exception doit être levée ou une valeur d'erreur retournée.

## Structure du Projet

Le projet est organisé de la manière suivante :

- **Directory:** `ex00/`
- **Files submitted:**
  - `incs/easyfind.hpp`
  - `Makefile`
  - `srcs/main.cpp`

### Description des Fichiers

- `incs/easyfind.hpp`: Contient la déclaration de la fonction template `easyfind`.
- `srcs/main.cpp`: Contient le point d'entrée du programme et la logique principale.
- `Makefile`: Fichier pour automatiser la compilation du projet.

## Compilation

Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```

Cette commande génère un exécutable nommé easyfind dans le répertoire courant.

## Exécution
Après la compilation, exécutez le programme avec la commande :

```bash
./easyfind
```

## Exercise 01: Span
L'objectif de l'exercice 01 consiste à créer une classe template en C++ pour gérer un container d'entiers et trouver les plus petites et grandes distances entre les éléments. Les fonctionnalités à implémenter incluent :

- `Span`: Une classe pour stocker un nombre maximum d'entiers et offrir des fonctions pour ajouter des nombres et calculer les plus petites et grandes distances entre les éléments.

## Structure du Projet
Le projet est organisé de la manière suivante :

- **Directory: ex01/**
- **Files submitted:**
  - `incs/Span.hpp`
  - `Makefile`
  - `srcs/Span.cpp`
  - `srcs/main.cpp`
    
### Description des Fichiers
- `incs/Span.hpp`: Contient la déclaration de la classe Span.
- `srcs/Span.cpp`: Contient l'implémentation de la classe Span.
- `srcs/main.cpp`: Contient le point d'entrée du programme et la logique principale.
- `Makefile`: Fichier pour automatiser la compilation du projet.

## Compilation
Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```
Cette commande génère un exécutable nommé span dans le répertoire courant.

## Exécution
Après la compilation, exécutez le programme avec la commande :

```bash
./span
```

## Exercise 02: MutantStack
L'objectif de l'exercice 02 consiste à créer une classe template en C++ dérivée de std::stack pour ajouter la fonctionnalité d'itération. Les fonctionnalités à implémenter incluent :

MutantStack: Une classe dérivée de std::stack qui offre des itérateurs pour parcourir les éléments de la pile.
## Structure du Projet
Le projet est organisé de la manière suivante :

- **Directory:** ex02/
- **Files submitted:**
  - `incs/MutantStack.hpp`
  - `Makefile`
  - `srcs/MutantStack.cpp`
  - `srcs/main.cpp`
    
### Description des Fichiers

  - `incs/MutantStack.hpp`: Contient la déclaration de la classe MutantStack.
  - `srcs/MutantStack.cpp`: Contient l'implémentation de la classe MutantStack.
  - `srcs/main.cpp`: Contient le point d'entrée du programme et la logique principale.
  - `Makefile`: Fichier pour automatiser la compilation du projet.

## Compilation
Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```
Cette commande génère un exécutable nommé mutantstack dans le répertoire courant.

## Exécution
Après la compilation, exécutez le programme avec la commande :

```bash
./mutantstack
```

## Fonctionnalités Communes
- Gestion des exceptions: Le programme démontre l'utilisation des exceptions pour gérer les erreurs de manière propre et sécurisée.
- Suivi des bonnes pratiques de codage C++98: Respect strict des conventions de codage et des standards de C++98.
Structure de code modulaire et maintenable: Le code est organisé de manière à être facilement compréhensible et extensible.

## Contributeurs
raveriss - Développeur principal

## Remarques
Ce projet suit les conventions de codage strictes pour C++98, évitant l'utilisation de fonctionnalités modernes et de conteneurs STL, sauf là où ils sont spécifiquement autorisés. Les bonnes pratiques pour la gestion de la mémoire et la portabilité sont également respectées.

## Ressources Utilisées
- [Apprenez à programmer en C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c)
- [Programmez en orienté objet avec C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c)
- [Apprenez à programmer en C++ sur codecademy](https://www.codecademy.com/catalog/language/c-plus-plus)
- [Introduction à C++ sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-introduction)
- [C++ Intermédiaire sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-intermediate)
