#include <iostream>
#include <fstream>
#include "Losers.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 4)
    {
        std::string filename = argv[1];
        Losers loser(filename);
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        loser.process(s1, s2);
    }
    else
    {
        std::cerr << "arguments count must be 3!" << std::endl;
    }
    return 0;
}