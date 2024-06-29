#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string *ideas;

public:
    Brain();
    Brain(const std::string ideas[100]);
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    virtual ~Brain();
    const std::string *getIdeas() const;
    void setIdeas(const std::string ideas[100]);
};

#endif