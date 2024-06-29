#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iomanip> 
#include <iostream>
class PhoneBook {
private:
    Contact contacts[8];
    int numContacts;
    std::string truncateString(std::string str, int length);
public:
    PhoneBook();
    void addContact_2(Contact contact);
    void addContact();
    int getNumberOfContacts() const;
    void displayContacts() const; 
    void searchContact_2();
    void searchContact();
    void exitPhonebook();
    Contact getContact(int index) const;
};

#endif




