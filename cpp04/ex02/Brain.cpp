#include "./Brain.hpp"

Brain::Brain()
{
    ideas = new std::string[100];
    std::cout << "Default constructor for Brain" << std::endl;
}
Brain::Brain(const std::string ideas[100])
{
    std::cout << "parametric constructor for Brain" << std::endl;

    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = ideas[i];
    }
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor for Brain" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout <<  "Copy assignment operator for Brain" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    delete[] ideas;
    std::cout << "Destructor for Brain" << std::endl;
}

const std::string *Brain::getIdeas() const
{
    return ideas;
}

void Brain::setIdeas(const std::string ideas[100])
{
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = ideas[i];
    }
}
