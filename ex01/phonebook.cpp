#include "phonebook.hpp"

static std::string get_field(const std::string &label)
{
    std::string field;

    while (true)
    {
        std::cout << label << ": ";
        if (!std::getline(std::cin, field))
            break;
        if (!field.empty())
            return field;
        std::cerr << "Field cannot be empty." << std::endl;
    }
    return field;
}

void Contact::setFields(void)
{
    _first_name     = get_field("First name");
    _last_name      = get_field("Last name");
    _nickname       = get_field("Nickname");
    while (true)
    {
        _phone_number = get_field("Phone number");
        if (_phone_number.length() == 10)
        {
            size_t i = 0;
            while (i < 10 && _phone_number[i] >= '0' && _phone_number[i] <= '9')
                i++;
            if (i == 10)
                break;
        }
        std::cerr << "Phone number must be exactly 10 digits." << std::endl;
    }
    _darkest_secret = get_field("Darkest secret");
}

void Contact::display(void) const
{
    std::cout << "First name     : " << _first_name << std::endl;
    std::cout << "Last name      : " << _last_name << std::endl;
    std::cout << "Nickname       : " << _nickname << std::endl;
    std::cout << "Phone number   : " << _phone_number << std::endl;
    std::cout << "Darkest secret : " << _darkest_secret << std::endl;
}

std::string Contact::getFirstName(void) const { return _first_name; }
std::string Contact::getLastName(void) const  { return _last_name; }
std::string Contact::getNickname(void) const  { return _nickname; }

PhoneBook::PhoneBook(void) : _count(0), _next(0) {}

void PhoneBook::add_cmd(void)
{
    _contacts[_next].setFields();
    _next = (_next + 1) % 8;
    if (_count < 8)
        _count++;
    std::cout << "Contact saved." << std::endl;
}

static std::string truncate(const std::string &s)
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

void PhoneBook::search_cmd(void) const
{
    std::string input;
    int         index;

    if (_count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << std::endl;
    for (int i = 0; i < _count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
    }
    std::cout << "Enter index: ";
    if (!std::getline(std::cin, input) || input.empty())
    {
        std::cerr << "Invalid index." << std::endl;
        return;
    }
    index = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            std::cerr << "Invalid index." << std::endl;
            return;
        }
        index = index * 10 + (input[i] - '0');
    }
    if (index >= _count)
    {
        std::cerr << "Index out of range." << std::endl;
        return;
    }
    _contacts[index].display();
}

int main(int argc, char **)
{
    PhoneBook   pb;
    std::string cmd;

    if (argc != 1)
    {
        std::cerr << "No arguments allowed." << std::endl;
        return 1;
    }
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "ADD")
            pb.add_cmd();
        else if (cmd == "SEARCH")
            pb.search_cmd();
        else if (cmd == "EXIT")
            break;
    }
    return 0;
}
