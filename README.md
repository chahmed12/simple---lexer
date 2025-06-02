# Analyseur Lexical Simple en C

Ce projet est un **analyseur lexical** de base écrit en **langage C**, qui permet de découper une ligne de code source (style C) en *tokens*.

---

## Fonctionnalités

Détecte automatiquement :
- **Mots-clés** (int, if, while, etc.)
- **Identifiants** (comme x, maVariable)
- **Nombres** (ex : 42)
- **Symboles** (+, =, ;, etc.)

Gère une seule ligne de code à la fois.

Code modulaire (fichiers séparés : main.c, lexer.c, lexer.h)

---

##  Structure du projet

simple-lexer/
├── lexer.c        # Fonctions d’analyse lexicale
├── lexer.h        # Déclarations des types et fonctions
├── main.c         # Programme principal
├── Makefile       # Fichier de compilation automatique
├── .gitignore     # Fichiers à ignorer par Git
└── README.md      # Description du projet

---

## Compilation et exécution

### Compiler avec `make`

```bash
make