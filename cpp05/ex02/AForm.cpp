#include "AForm.hpp"

AForm::AForm() : _name("Default"),
               _is_form_signed(false),
               _grade_need_to_sign(150),
               _grade_need_to_execute(150)
{
    std::cout << "Form default constructer called" << std::endl;
}


AForm::AForm(std::string name, bool is_form_signed, int const grade_need_to_sign, int const grade_need_to_execute)
    : _name(name),
      _is_form_signed(is_form_signed),
      _grade_need_to_sign(grade_need_to_sign),
      _grade_need_to_execute(grade_need_to_execute)
{
    exeption_helper();
    std::cout << "Form parametrical constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name),
                                _is_form_signed(other._is_form_signed),
                                _grade_need_to_sign(other._grade_need_to_sign),
                                _grade_need_to_execute(other._grade_need_to_execute)
{
    std::cout << "Form copy constructor called" << std::endl;
    if (this != &other)
        *this = other;
    exeption_helper();
}

AForm   &AForm::operator=(const AForm &other)  {
    std::cout <<  "Form Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    exeption_helper();
    setName(other.getName());
    _is_form_signed = other.getIsFormSigned();
    setGradeNeedToSign(other.getGradeNeedToSign());
    setGradeNeedToExecute(other.getGradeNeedToExecute());
    return (*this);
}

void    AForm::beSigned(const Bureaucrat &target)  {
    if (_is_form_signed)
        throw SignedException();
    if (target.getGrade() <= _grade_need_to_sign)
        _is_form_signed = true;
    else
        throw GradeTooLowException();
}

std::string const AForm::getName() const { 
    return (_name); 
}
bool AForm::getIsFormSigned() const { 
    return (_is_form_signed); \
}
int  AForm::getGradeNeedToSign() const { 
    return (_grade_need_to_sign); 
}
int  AForm::getGradeNeedToExecute() const { 
    return (_grade_need_to_execute); 
}

void AForm::setName(std::string const name)
{
    std::string *tmp = (std::string *)&_name;
    *tmp = name;
}
void AForm::setGradeNeedToSign(int n)
{
    int *tmp = (int *)&_grade_need_to_sign;
    *tmp = n;
}
void AForm::setGradeNeedToExecute(int n)
{
    int *tmp = (int *)&_grade_need_to_execute;
    *tmp = n;
}

char const *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
char const *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
char const *AForm::SignedException::what() const throw()
{
    return ("Form is already signed");
}

void AForm::exeption_helper()
{
    if (_grade_need_to_execute > 150 || _grade_need_to_sign > 150){
        throw GradeTooLowException();
    }
    else if (_grade_need_to_execute < 1 || _grade_need_to_sign < 1)
    {
        throw GradeTooHighException();
    }
}

std::ostream& operator<<(std::ostream &out, AForm const &form) {
    out << "Form data:" << std::endl;
    out << "Name: " << form.getName() << std::endl;
    out << "Is Form Signed: " << (form.getIsFormSigned() ? "Yes" : "No") << std::endl;
    out << "Grade Need To Sign: " << form.getGradeNeedToSign() << std::endl;
    out << "Grade Need To Execute: " << form.getGradeNeedToExecute() << std::endl;
    return out;
}

AForm::~AForm(){std::cout << "Form destructor called" <<  std::endl;}
