#pragma once

#include <string>
#include <vector>
#include <optional>
#include "Token.hpp"

class Tokenizer
{
public:
    Tokenizer(std::string source);
    std::vector<Token> tokenize();
    void resetCurrentIndex();

private:
    int _currentIndex = 0;
    const std::string _source;
    [[nodiscard]] std::optional<char> peek(int ahead = 0) const;
    char consume();
};
