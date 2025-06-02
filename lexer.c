#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

const char* keywords[] = { "int", "float", "if", "else", "while", "return" };
int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

int is_keyword(const char *word) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_letter(char c) {
    return isalpha(c) || c == '_';
}

int is_digit(char c) {
    return isdigit(c);
}

void print_token(Token token) {
    switch (token.type) {
        case TOKEN_KEYWORD:
            printf("TOKEN_KEYWORD(\"%s\")\n", token.value); break;
        case TOKEN_IDENTIFIER:
            printf("TOKEN_IDENTIFIER(\"%s\")\n", token.value); break;
        case TOKEN_NUMBER:
            printf("TOKEN_NUMBER(\"%s\")\n", token.value); break;
        case TOKEN_SYMBOL:
            printf("TOKEN_SYMBOL(\"%s\")\n", token.value); break;
        default:
            printf("TOKEN_UNKNOWN(\"%s\")\n", token.value);
    }
}

void tokenize_line(const char *line) {
    int i = 0;
    while (line[i] != '\0') {
        if (isspace(line[i])) {
            i++;
            continue;
        }

        Token token;
        int j = 0;

        if (is_letter(line[i])) {
            // Identifiant ou mot-clé
            while (is_letter(line[i]) || is_digit(line[i])) {
                token.value[j++] = line[i++];
            }
            token.value[j] = '\0';
            token.type = is_keyword(token.value) ? TOKEN_KEYWORD : TOKEN_IDENTIFIER;
        }
        else if (is_digit(line[i])) {
            // Nombre
            while (is_digit(line[i])) {
                token.value[j++] = line[i++];
            }
            token.value[j] = '\0';
            token.type = TOKEN_NUMBER;
        }
        else if (ispunct(line[i])) {
            // Symbole ponctuel
            token.value[0] = line[i++];
            token.value[1] = '\0';
            token.type = TOKEN_SYMBOL;
        }
        else {
            token.value[0] = line[i++];
            token.value[1] = '\0';
            token.type = TOKEN_UNKNOWN;
        }

        print_token(token);
    }
}