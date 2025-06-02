#include <stdio.h>
#include "lexer.h"

int main() {
    char line[256];

    printf("Entrez une ligne de code :\n> ");
    if (fgets(line, sizeof(line), stdin)) {
        tokenize_line(line);
    } else {
        printf("Erreur de lecture.\n");
    }

    return 0;
}