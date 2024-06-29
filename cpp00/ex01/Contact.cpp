#include "Contact.hpp"

Contact::~Contact(void){
    return;
}

Contact::Contact(std::string firstName, std::string lastName, std::string phoneNumber, std::string darkestSecret, std::string nickname) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
    this->nickname = nickname;
}

void Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
    this->darkestSecret = darkestSecret;
}

void Contact::setNickname(std::string nickname) {
    this->nickname = nickname;
}

std::string Contact:: getFirstName()const{
    return firstName;
}

std::string Contact:: getLastName() const{
    return lastName;
}

std::string Contact:: getNickname() const{
    return nickname;
}

std::string Contact:: getPhoneNumber() const{
    return phoneNumber;
}

std::string Contact::getDarkestSecret()const {
    return darkestSecret;
}

bool Contact:: isEmpty() {
    return firstName.empty() && lastName.empty() && phoneNumber.empty() && darkestSecret.empty();
}