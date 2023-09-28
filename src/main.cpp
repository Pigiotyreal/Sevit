#include "lexer.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "ERR: Please provide a file!" << std::endl;
        return 1;
    } else if (std::string(argv[1]).substr(std::string(argv[1]).find_last_of(".") + 1) != "sev") {
        std::cerr << "ERR: Please provide a file ending with .sev!" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.good()) {
        std::cerr << "ERR: File does not exist!" << std::endl;
        return 1;
    }

    std::string text;
    std::string line;
    while (std::getline(file, line)) {
        text += line + "\n";
    }

    file.close();

    Lexer lexer(text);
    std::vector<Token> tokens = lexer.lex();

    for (Token token : tokens) {
        if (token.type != TokenType::END_OF_FILE) {
            std::cout << token.value << std::endl;
        }
    }

    std::cout << "Compiling " << argv[1] << "...\n";
    return 0;
}