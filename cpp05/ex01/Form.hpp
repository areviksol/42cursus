#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;
#include <iostream>

class Form
{
private:
    std::string const _name;
    bool _is_form_signed;
    int const _grade_need_to_sign;
    int const _grade_need_to_execute;

public:
    Form();
    Form(std::string const name, bool is_form_signed, int const grade_need_to_sign, int const grade_need_to_execute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    virtual ~Form();

    // getters
    std::string const getName() const;
    bool getIsFormSigned() const;
    int   getGradeNeedToSign() const;
    int   getGradeNeedToExecute() const;

    // setters
    void setName(std::string const name);
    void setIsFormSigned();
    void setGradeNeedToSign(int n);
    void setGradeNeedToExecute(int n);

    // helper for exeption
    void exeption_helper();

    // required member function
    void beSigned(const Bureaucrat &target);

    //classes for exeptionsa
    class GradeTooHighException : public std::exception
    {
    public:
        char const *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        char const *what() const throw();
    };

    class SignedException : public std::exception       
    {
    public: 
        char const  *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, Form const &i);

#endif