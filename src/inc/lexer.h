#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

enum class TokenType {
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LPAREN,
    RPAREN,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType type = TokenType::END_OF_FILE, std::string value = "") : type(type), value(value) {}
};

class Lexer {
    private:
        std::string text;
        int pos;
        char current_char;
        std::vector<Token> tokens;

        void advance();
        void skip_whitespace();
        int integer();
        Token get_next_token();
    public:
        Lexer(std::string text);
        std::vector<Token> lex();
};

#endif