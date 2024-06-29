#include "Losers.hpp"

Losers::Losers(std::string &filename): _in(filename)
{
    this->_out = this->_in + ".replace";
}

Losers::~Losers(void){}

std::string& Losers::replace(std::string& str, std::size_t pos, std::size_t count, const std::string& replaceStr)
{
    if (pos > str.length())
        throw std::out_of_range("position is not valid !!!!!");

    if (count > str.length() - pos)
        count = str.length() - pos;

    str.erase(pos, count);
    str.insert(pos, replaceStr);

    return str;
}


void Losers::process(const std::string &s1, const std::string &s2)
{
    // Open the input file
    std::ifstream inputFile(this->_in);
    if (!inputFile)
    {
        std::cerr << "Failed to open input file: " << this->_in << std::endl;
        return;
    }

    // Create the output file
    std::ofstream outputFile(this->_out);
    if (!outputFile)
    {
        std::cerr << "Failed to create file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            replace(line, pos, s1.length(), s2);
            pos += s2.length();
        }

        outputFile << line << std::endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << " New" <<  this->_out << "file created: " << std::endl;
}
