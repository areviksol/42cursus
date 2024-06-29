#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

int main()
{
    PhoneBook phonebook;
    std::string command;
    if (std::cin.eof())
    {
        exit(0);
    }
    while (true)
    {
        if (std::cin.eof())
        {
            exit(0);
        }
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContact();
        }
        else if (command == "EXIT")
        {
            exit(0);
            // phonebook.exitPhonebook();
        }
        else
        {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}
