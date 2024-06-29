#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{

private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& _name, int _grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    virtual ~Bureaucrat();

    std::string const getName() const;
    int getGrade() const;
    void increment();
    void decrement();

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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &i);

#endif