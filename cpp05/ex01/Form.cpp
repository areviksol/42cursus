#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"),
               _is_form_signed(false),
               _grade_need_to_sign(150),
               _grade_need_to_execute(150)
{
    std::cout << "Form default constructer called" << std::endl;
}

Form::Form(std::string name, bool is_form_signed, int const grade_need_to_sign, int const grade_need_to_execute)
    : _name(name),
      _is_form_signed(is_form_signed),
      _grade_need_to_sign(grade_need_to_sign),
      _grade_need_to_execute(grade_need_to_execute)
{
    exeption_helper();
    std::cout << "Form parametrical constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name),
                                _is_form_signed(other._is_form_signed),
                                _grade_need_to_sign(other._grade_need_to_sign),
                                _grade_need_to_execute(other._grade_need_to_execute)
{
    std::cout << "Form copy constructor called" << std::endl;
    if (this != &other)
        *this = other;
    exeption_helper();
}

Form   &Form::operator=(const Form &other)  {
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

void    Form::beSigned(const Bureaucrat &target)  {
    if (_is_form_signed)
        throw SignedException();
    if (target.getGrade() <= _grade_need_to_sign)
        _is_form_signed = true;
    else
        throw GradeTooLowException();
}

std::string const Form::getName() const { 
    return (_name); 
}
bool Form::getIsFormSigned() const { 
    return (_is_form_signed); \
}
int  Form::getGradeNeedToSign() const { 
    return (_grade_need_to_sign); 
}
int  Form::getGradeNeedToExecute() const { 
    return (_grade_need_to_execute); 
}

void Form::setName(std::string const name)
{
    std::string *tmp = (std::string *)&_name;
    *tmp = name;
}
void Form::setGradeNeedToSign(int n)
{
    int *tmp = (int *)&_grade_need_to_sign;
    *tmp = n;
}
void Form::setGradeNeedToExecute(int n)
{
    int *tmp = (int *)&_grade_need_to_execute;
    *tmp = n;
}

char const *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
char const *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
char const *Form::SignedException::what() const throw()
{
    return ("Form is already signed");
}

void Form::exeption_helper()
{
    if (_grade_need_to_execute > 150 || _grade_need_to_sign > 150)
    {
        throw GradeTooLowException();
    }
    else if (_grade_need_to_execute < 1 || _grade_need_to_sign < 1)
    {
        throw GradeTooHighException();
    }
}

std::ostream& operator<<(std::ostream &out, Form const &form) {
    out << "Form data:" << std::endl;
    out << "Name: " << form.getName() << std::endl;
    out << "Is Form Signed: " << (form.getIsFormSigned() ? "Yes" : "No") << std::endl;
    out << "Grade Need To Sign: " << form.getGradeNeedToSign() << std::endl;
    out << "Grade Need To Execute: " << form.getGradeNeedToExecute() << std::endl;
    return out;
}

Form::~Form(){std::cout << "Form destructor called" <<  std::endl;}
