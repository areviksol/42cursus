#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const name);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

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

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &i);

#endif