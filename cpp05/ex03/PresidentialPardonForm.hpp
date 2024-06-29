#ifndef PRESIDENTAL_PARDON_FORM_HPP
#define PRESIDENTAL_PARDON_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const name);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

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

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &i);

#endif