#include <unordered_map>
#include <string>
#include "TokenType.hpp"

std::unordered_map<std::string, TokenType> tokenMap{
    {"return", TokenType::_return},
    {"rakam", TokenType::rakam},
    {";", TokenType::semicolon},
    {"identifier", TokenType::identifier},
};