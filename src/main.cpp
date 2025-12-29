#include <iostream>
#include <sstream>
#include <fstream>

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
        std::fstream input(argv[2], std::ios::in);
        contents_stream << input.rdbuf();
        content = contents_stream.str();
    }

    std::cout << content << std::endl;

    return 0;
}