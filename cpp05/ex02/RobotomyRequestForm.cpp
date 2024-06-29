#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm()
    :   AForm("Default", false, 72, 45)

{
    std::cout << "RobotomyRequestForm default constructer called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
    : AForm(name, false, 72, 45)
{
    setGradeNeedToSign(72);
    setGradeNeedToExecute(45);
    std::cout << "RobotomyRequestForm parametrical constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this == &other) {
        return *this;
    }
    AForm::operator=(other); 
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string const RobotomyRequestForm::getName() const {
    return _name; 
}

bool RobotomyRequestForm::getIsFormSigned() const {
    return _is_form_signed; 
}

int  RobotomyRequestForm::getGradeNeedToSign() const {
    return _grade_need_to_sign; 
}

int  RobotomyRequestForm::getGradeNeedToExecute() const {
    return _grade_need_to_execute;
}

void RobotomyRequestForm::setName(std::string const name) {
    std::string& non_const_name = const_cast<std::string&>(_name);
    non_const_name = name;
}

void RobotomyRequestForm::setIsFormSigned() {
    _is_form_signed = true;
}

void RobotomyRequestForm::setGradeNeedToSign(int n) {
    int& non_const_grade_need_to_sign = const_cast<int&>(_grade_need_to_sign);
    non_const_grade_need_to_sign = n;
}

void RobotomyRequestForm::setGradeNeedToExecute(int n) {
    int& non_const_grade_need_to_execute = const_cast<int&>(_grade_need_to_execute);
    non_const_grade_need_to_execute = n; 
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeNeedToExecute()) {
        throw GradeTooLowException();
    }else if(executor.getGrade() > getGradeNeedToExecute()) {
        throw GradeTooHighException();
    }else if (!getIsFormSigned()) {
        throw SignedException();
    }
    std::cout << "*drilling noises *\n";
    std::srand(std::time(NULL));
    if (std::rand() % 100 < 50)
        std::cout << getName() <<  " robotomized not successfully" << std::endl;
	else
        std::cout << getName() <<  " robotomized successfully" << std::endl;
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &i) {
    out << "Form data:" << std::endl;
    out << "Name: " << i.getName() << std::endl;
    out << "Is Form Signed: " << (i.getIsFormSigned() ? "Yes" : "No") << std::endl;
    out << "Grade Need To Sign: " << i.getGradeNeedToSign() << std::endl;
    out << "Grade Need To Execute: " << i.getGradeNeedToExecute() << std::endl;
    return out;
}
