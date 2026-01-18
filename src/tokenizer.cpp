#include "tokenizer.hpp"
#include "TokenMap.hpp"
#include <cctype>
#include <sstream>
#include <iostream>

Tokenizer::Tokenizer(std::string source) : _source(std::move(source)) {};

inline void Tokenizer::resetCurrentIndex()
{
    _currentIndex = 0;
}

[[nodiscard]] std::optional<char> Tokenizer::peek(int ahead) const
{
    if (_currentIndex + ahead > _source.size())
        return std::nullopt;
    else
        return _source.at(_currentIndex + ahead);
}

char Tokenizer::consume()
{
    char ch = _source.at(_currentIndex);
    _currentIndex++;
    return ch;
}

std::vector<Token> Tokenizer::tokenize()
{
    std::vector<Token> tokens;
    std::string buffer;

    while (_currentIndex < _source.size())
    {
        auto currentChar = peek();
        if (!currentChar)
            break;

        if (std::isspace(currentChar.value()))
        {
            consume();
            continue;
        }
        if (currentChar.value() == ';')
        {
            tokens.push_back({.type = TokenType::semicolon, .value = ";"});
            consume();
            continue;
        }

        if (std::isdigit(currentChar.value()))
        {
            while (peek().has_value() && std::isdigit(peek().value()))
            {
                buffer += consume();
            }

            tokens.push_back({TokenType::rakam, buffer});
            buffer.clear();
            continue;
        }

        if (std::isalpha(currentChar.value()))
        {
            while (peek().has_value() && (std::isalpha(peek().value()) || peek().value() == '_'))
            {
                buffer += consume();
            }

            if (tokenMap.find(buffer) != tokenMap.end())
            {
                tokens.push_back({tokenMap[buffer], buffer});
            }
            else
            {
                tokens.push_back({TokenType::identifier, buffer});
            }
            buffer.clear();
            continue;
        }
        consume(); // skipping fucked up charac for now
    }

    return tokens;
}
