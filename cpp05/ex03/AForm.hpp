#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
protected:
    std::string const _name;
    bool _is_form_signed;
    int const _grade_need_to_sign;
    int const _grade_need_to_execute;

public:
    AForm();
    AForm(std::string const name, bool is_form_signed, int const grade_need_to_sign, int const grade_need_to_execute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

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

    // required member function
    void beSigned(const Bureaucrat &target);
    virtual void execute(Bureaucrat const & executor) const = 0;
    //classes for exeptions
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

std::ostream &operator<<(std::ostream &out, AForm const &i);

#endif