#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    :   AForm("Default", false, 145, 137)

{
    std::cout << "ShrubberyCreationForm default constructer called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
    : AForm(name, false, 145, 137)
{
    std::cout << "ShrubberyCreationForm parametrical constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this == &other) {
        return *this;
    }
    AForm::operator=(other); 
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string const ShrubberyCreationForm::getName() const {
    return _name; 
}

bool ShrubberyCreationForm::getIsFormSigned() const {
    return _is_form_signed; 
}

int  ShrubberyCreationForm::getGradeNeedToSign() const {
    return _grade_need_to_sign; 
}

int  ShrubberyCreationForm::getGradeNeedToExecute() const {
    return _grade_need_to_execute;
}

void ShrubberyCreationForm::setName(std::string const name) {
    std::string& non_const_name = const_cast<std::string&>(_name);
    non_const_name = name;
}

void ShrubberyCreationForm::setIsFormSigned() {
    _is_form_signed = true;
}

void ShrubberyCreationForm::setGradeNeedToSign(int n) {
    int& non_const_grade_need_to_sign = const_cast<int&>(_grade_need_to_sign);
    non_const_grade_need_to_sign = n;
}

void ShrubberyCreationForm::setGradeNeedToExecute(int n) {
    int& non_const_grade_need_to_execute = const_cast<int&>(_grade_need_to_execute);
    non_const_grade_need_to_execute = n; 
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeNeedToExecute()) {
        throw GradeTooLowException();
    }

    if (!getIsFormSigned()) {
        throw SignedException();
    }

    std::string filename = _name + "_shrubbery";
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    outFile << "        _-_   _-_" << std::endl;
    outFile << "     /~~   ~~\\/" << std::endl;
    outFile << " /~~           ~~\\|" << std::endl;
    outFile << "{                 }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\\\ //  ~" << std::endl;
    outFile << "_- -   | | _- _" << std::endl;
    outFile << "  _ -  | |   -_" << std::endl;
    outFile << "      // \\\\" << std::endl;

    outFile.close();

    std::cout << "ShrubberyCreationForm executed successfully. Check " << filename << " for ASCII trees." << std::endl;
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &i) {
    out << "Form data:" << std::endl;
    out << "Name: " << i.getName() << std::endl;
    out << "Is Form Signed: " << (i.getIsFormSigned() ? "Yes" : "No") << std::endl;
    out << "Grade Need To Sign: " << i.getGradeNeedToSign() << std::endl;
    out << "Grade Need To Execute: " << i.getGradeNeedToExecute() << std::endl;
    return out;
}
