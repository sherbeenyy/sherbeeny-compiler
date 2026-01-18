#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <optional>
#include <unordered_map>
#include "Token.hpp"
#include "tokenizer.hpp"

int main(int argc, char *argv[])
{
    int user_argc = argc - 1;
    if (user_argc != 2)
    {
        std::cerr << "INVALID ARGS\n";
        std::cerr << "USAGE: sherbeeny <main.sherb>\n";
        return 1;
    }

    std::string content;
    {
        std::stringstream contents_stream;
        std::ifstream inputFile(argv[2]);
        if (!inputFile)
        {
            std::cerr << "ERROR: Could not open file " << argv[2] << "\n";
            return -1;
        }
        contents_stream << inputFile.rdbuf();
        content = contents_stream.str();
    }

    Tokenizer tokenizer(std::move(content));
    std::vector<Token> results = tokenizer.tokenize();

    // printing tokens for debug
    for (const auto &token : results)
    {
        switch (token.type)
        {
        case TokenType::_return:
            std::cout << "_return";
            break;
        case TokenType::rakam:
            std::cout << "rakam";
            break;
        case TokenType::semicolon:
            std::cout << "semicolon";
            break;
        case TokenType::identifier:
            std::cout << "identifier";
            break;
        }
        if (token.value)
        {
            std::cout << ": " << *token.value;
        }
        std::cout << "\n";
    }

    return 0;
}