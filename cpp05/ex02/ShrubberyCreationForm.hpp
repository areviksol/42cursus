#ifndef SHRUBERRY_CREATION_FORM_HPP
#define SHRUBERRY_CREATION_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const name);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    // getters
    std::string const getName() const;
    bool getIsFormSigned() const;
    int  getGradeNeedToSign() const;
    int  getGradeNeedToExecute() const;

    // setters
    void setName(std::string const name);
    void setIsFormSigned();
    void setGradeNeedToSign(int n);
    void setGradeNeedToExecute(int n);

    // helper for exeption
    void exeption_helper();
    void execute(Bureaucrat const & executor) const ;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &i);

#endif