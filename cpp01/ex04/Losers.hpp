#ifndef LOSERS_HPP
#define LOSERS_HPP

#include <iostream>
#include <fstream>

class Losers
{
public:
    Losers(std::string &filename);
    ~Losers();
    std::string& replace(std::string& str, std::size_t pos, std::size_t count, const std::string& replaceStr);
    void process(const std::string &s1, const std::string &s2);
private:
    std::string _in;
    std::string _out;
};

#endif