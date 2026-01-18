#pragma once

#include <optional>
#include <string>
#include "TokenType.hpp"

struct Token
{
    TokenType type;
    std::optional<std::string> value;
};