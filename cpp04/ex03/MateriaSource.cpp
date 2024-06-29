#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default constructor for MateriaSource" <<std::endl;
    for (int i = 0; i < 4; ++i)
    {
        _learnedMaterias[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "Copy constructor for MateriaSource" <<std::endl;

    for (int i = 0; i < 4; ++i)
    {
        if (other._learnedMaterias[i])
        {
            _learnedMaterias[i] = other._learnedMaterias[i]->clone();
        }
        else
        {
            _learnedMaterias[i] = nullptr;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "assignment operator for MateriaSource" <<std::endl;

    if (this == &other)
    {
        return *this;
    }
    for (int i = 0; i < 4; ++i)
    {
        delete _learnedMaterias[i];
        _learnedMaterias[i] = nullptr;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (other._learnedMaterias[i])
        {
            _learnedMaterias[i] = other._learnedMaterias[i]->clone();
        }
        else
        {
            _learnedMaterias[i] = nullptr;
        }
    }

    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "Destructor for MateriaSource" <<std::endl;
    for (int i = 0; i < 4; ++i)
    {
        delete _learnedMaterias[i];
        _learnedMaterias[i] = nullptr;
    }
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
    {
        return; 
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!_learnedMaterias[i])
        {
            _learnedMaterias[i] = materia->clone();
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
        {
            return _learnedMaterias[i]->clone();
        }
    }

    return nullptr;
}
