#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_SYMBOL,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[64];
} Token;

int is_keyword(const char *word);
int is_letter(char c);
int is_digit(char c);
void tokenize_line(const char *line);

#endif