#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm()
    :   AForm("Default", false, 25, 5)

{
    std::cout << "PresidentialPardonForm default constructer called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
    : AForm(name, false, 25, 5)
{
    std::cout << "PresidentialPardonForm parametrical constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this == &other) {
        return *this;
    }
    AForm::operator=(other); 
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

std::string const PresidentialPardonForm::getName() const {
    return _name; 
}

bool PresidentialPardonForm::getIsFormSigned() const {
    return _is_form_signed; 
}

int  PresidentialPardonForm::getGradeNeedToSign() const {
    return _grade_need_to_sign; 
}

int  PresidentialPardonForm::getGradeNeedToExecute() const {
    return _grade_need_to_execute;
}

void PresidentialPardonForm::setName(std::string const name) {
    std::string& non_const_name = const_cast<std::string&>(_name);
    non_const_name = name;
}

void PresidentialPardonForm::setIsFormSigned() {
    _is_form_signed = true;
}

void PresidentialPardonForm::setGradeNeedToSign(int n) {
    int& non_const_grade_need_to_sign = const_cast<int&>(_grade_need_to_sign);
    non_const_grade_need_to_sign = n;
}

void PresidentialPardonForm::setGradeNeedToExecute(int n) {
    int& non_const_grade_need_to_execute = const_cast<int&>(_grade_need_to_execute);
    non_const_grade_need_to_execute = n; 
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeNeedToExecute()) {
        throw GradeTooLowException();
    }else if(executor.getGrade() > getGradeNeedToExecute()) {
        throw GradeTooHighException();
    }else if (!getIsFormSigned()) {
        throw SignedException();
    }
    std::cout << _name << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &i) {
    out << "Form data:" << std::endl;
    out << "Name: " << i.getName() << std::endl;
    out << "Is Form Signed: " << (i.getIsFormSigned() ? "Yes" : "No") << std::endl;
    out << "Grade Need To Sign: " << i.getGradeNeedToSign() << std::endl;
    out << "Grade Need To Execute: " << i.getGradeNeedToExecute() << std::endl;
    return out;
}
