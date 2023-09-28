#include "inc/lexer.h"

Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_char = this->text[this->pos];
}

void Lexer::advance() {
    this->pos++;
    if (this->pos > this->text.length() - 1) {
        this->current_char = '\0';
    } else {
        this->current_char = this->text[this->pos];
    }
}

void Lexer::skip_whitespace() {
    while (this->current_char != '\0' && isspace(this->current_char)) {
        this->advance();
    }
}

int Lexer::integer() {
    std::string result = "";
    while (this->current_char != '\0' && isdigit(this->current_char)) {
        result += this->current_char;
        this->advance();
    }
    return std::stoi(result);
}

Token Lexer::get_next_token() {
    while (this->current_char != '\0') {
        if (isspace(this->current_char)) {
            this->skip_whitespace();
            continue;
        }

        if (isdigit(this->current_char)) {
            return Token(TokenType::NUMBER, std::to_string(this->integer()));
        }

        if (this->current_char == '+') {
            this->advance();
            return Token(TokenType::PLUS, "+");
        }

        if (this->current_char == '-') {
            this->advance();
            return Token(TokenType::MINUS, "-");
        }

        if (this->current_char == '*') {
            this->advance();
            return Token(TokenType::MULTIPLY, "*");
        }

        if (this->current_char == '/') {
            this->advance();
            return Token(TokenType::DIVIDE, "/");
        }

        if (this->current_char == '(') {
            this->advance();
            return Token(TokenType::LPAREN, "(");
        }

        if (this->current_char == ')') {
            this->advance();
            return Token(TokenType::RPAREN, ")");
        }

        std::cerr << "ERR: Invalid character '" << this->current_char << "'!" << std::endl;
        exit(1);
    }
    return Token(TokenType::END_OF_FILE, "");
}

std::vector<Token> Lexer::lex() {
    while (this->current_char != '\0') {
        this->tokens.push_back(this->get_next_token());
    }
    return this->tokens;
}