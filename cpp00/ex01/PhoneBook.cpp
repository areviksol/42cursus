#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "./helper.cpp"

PhoneBook::PhoneBook()
{
    numContacts = 0;
}

void PhoneBook::addContact_2(Contact contact)
{
    if (numContacts == 8)
    {
        for (int i = 0; i < 7; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contacts[7] = contact;
    }
    else
    {
        contacts[numContacts] = contact;
        numContacts++;
    }
}

void PhoneBook::addContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::cout << "Enter first name: ";
    while (true)
    {
        if (!std::getline(std::cin, firstName))
        {
            if (std::cin.eof())
            {
                std::cout << "Exiting Phonebook." << std::endl;
                exit(0);
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid first_name: " << std::endl;
                continue;
            }
        }
        if (firstName.empty())
        {
            std::cout << "Invalid input. Please enter a valid first name: ";
            continue;
        }
        if (allCharactersAreAlpha(firstName))
        {
            break;
        }
        std::cout << "Invalid input. Please enter a valid first name: ";
    }
    std::cout << "Enter last name: ";
    while (true)
    {
        if (!std::getline(std::cin, lastName))
        {
            if (std::cin.eof())
            {
                std::cout << "Exiting Phonebook." << std::endl;
                exit(0);
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid lastname: " << std::endl;
                continue;
            }
        }
        if (lastName.empty())
        {
            std::cout << "Invalid input. Please enter a valid last name: ";
            continue;
        }
        if (allCharactersAreAlpha(lastName))
        {
            break;
        }
        std::cout << "Invalid input. Please enter a valid last name: ";
    }
    std::cout << "Enter nickname: ";
    while (true)
    {
        if (!std::getline(std::cin, nickname))
        {
            if (std::cin.eof())
            {
                std::cout << "Exiting Phonebook." << std::endl;
                exit(0);
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a nickname: " << std::endl;
                continue;
            }
        }
        if (nickname.empty())
        {
            std::cout << "Invalid input. Please enter a valid nick name: ";
            continue;
        }
        if (allCharactersAreAlpha(nickname))
        {
            break;
        }
        std::cout << "Invalid input. Please enter a valid nick name: ";
    }
    std::cout << "Enter phone number: ";
    while (true)
    {
        if (!std::getline(std::cin, phoneNumber))
        {
            if (std::cin.eof())
            {
                std::cout << "Exiting Phonebook." << std::endl;
                exit(0);
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid phone number: " << std::endl;
                continue;
            }
        }
        if (phoneNumber.empty())
        {
            std::cout << "Invalid input. Please enter a valid phone number: ";
            continue;
        }
        if (allCharactersAreDigit(phoneNumber))
        {
            break;
        }
        std::cout << "Invalid input. Please enter a valid phone number: ";
    }
    std::cout << "Enter darkest secret: ";
    while (true)
    {
        if (!std::getline(std::cin, darkestSecret))
        {
            if (std::cin.eof())
            {
                std::cout << "Exiting Phonebook." << std::endl;
                exit(0);
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid darkestSecret: " << std::endl;
                continue;
            }
        }
        if (darkestSecret.empty())
        {
            std::cout << "Invalid input. Please enter a valid darkestSecret: ";
            continue;
        }
        else
        {
            break;
        }
        std::cout << "Invalid input. Please enter a valid darkestSecret: ";
    }
    Contact newContact(firstName, lastName, phoneNumber, darkestSecret, nickname);
    this->addContact_2(newContact);
}

void PhoneBook::searchContact_2()
{
    std::cout << "     Index | First name | Last name  | Nickname  " << std::endl;
    for (int i = 0; i < numContacts; i++)
    {
        std::cout << std::setw(10) << std::right << i << " | ";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getFirstName(), 10) << " | ";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getLastName(), 10) << " | ";
    }

    int index;
    std::cout << "Enter the index of the contact you want to display: ";
    std::cin >> index;
    if (std::cin.eof())
    {
        exit(0);
    }
    if (index >= 0 && index < numContacts)
    {
        std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    }
    else
    {
        if (std::cin.eof())
        {
            exit(0);
        }

        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    }
}

void PhoneBook::searchContact()
{
    if (this->getNumberOfContacts() == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
    }
    else
    {
        this->displayContacts();
        int index;
        std::cout << "Enter the index of the contact you want to display: ";
        int flag = 0;
        while (flag != 2)
        {
            std::cin >> index;
            if (std::cin.eof())
            {
                exit(0);
            }
            if (std::cin.fail())
            {
                std::cout << "Invalid input. Please enter a valid index." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter the index of the contact you want to display: ";
            }
            else if (index < 0 || index >= this->getNumberOfContacts())
            {
                std::cout << "Invalid index. Please enter an index between 0 and " << this->getNumberOfContacts() - 1 << "." << std::endl;
                std::cout << "Enter the index of the contact you want to display: ";
            }
            else
            {
                flag = 2;
                std::cout << std::setw(10) << "Index"
                          << " | " << std::setw(10) << "First name"
                          << " | " << std::setw(10) << "Last name"
                          << " | " << std::setw(10) << "Nickname" << std::endl;
                std::cout << std::setw(10) << index << " | " << std::setw(10) << this->getContact(index).getFirstName().substr(0, 10) << " | " << std::setw(10) << this->getContact(index).getLastName().substr(0, 10) << " | " << std::setw(10) << std::endl;
                std::cout << "First name: " << this->getContact(index).getFirstName() << std::endl;
                std::cout << "Last name: " << this->getContact(index).getLastName() << std::endl;
                std::cout << "Nick name: " << this->getContact(index).getNickname() << std::endl;
                std::cout << "Phone number: " << this->getContact(index).getPhoneNumber() << std::endl;
                std::cin.ignore();
                if (std::cin.eof())
                {
                    exit(0);
                }
            }
        }
    }
}
void PhoneBook::exitPhonebook()

{

     exit(0);
}

std::string PhoneBook::truncateString(std::string str, int length)
{
    if (static_cast<int>(str.length()) > length)
    {
        str = str.substr(0, length - 1) + ".";
    }
    return str;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << std::right << "Index"
              << " | ";
    std::cout << std::setw(10) << std::right << "First name"
              << " | ";
    std::cout << std::setw(10) << std::right << "Last name"
              << " | ";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

    for (int i = 0; i < numContacts; i++)
    {
        const Contact &contact = contacts[i];
        std::cout << std::setw(10) << std::right << i << " | ";
        std::cout << std::setw(10) << std::right << (contact.getFirstName().length() > 10 ? contact.getFirstName().substr(0, 9) + "." : contact.getFirstName());
        std::cout << " | ";
        std::cout << std::setw(10) << std::right << (contact.getLastName().length() > 10 ? contact.getLastName().substr(0, 9) + "." : contact.getLastName());
        std::cout << " | ";
        std::cout << std::setw(10) << std::right << (contact.getLastName().length() > 10 ? contact.getLastName().substr(0, 9) + "." : contact.getLastName()) << std::endl;
    }
}

int PhoneBook::getNumberOfContacts() const
{
    return numContacts;
}

Contact PhoneBook::getContact(int index) const
{
    return contacts[index];
}