#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string nickname;
    std::string darkestSecret;
public:
    Contact() {}
    Contact(std::string firstName, std::string lastName, std::string phoneNumber, std::string darkestSecret, std::string nickname);
    ~Contact(void);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickname(std::string nickname);
    void setPhoneNumber(std::string phoneNumber);
    void setDarkestSecret(std::string darkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    std::string getNickname() const;
    bool isEmpty();
};

#endif