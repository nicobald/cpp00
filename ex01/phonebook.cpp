#include "phonebook.hpp"

std::string prompt(void)
{
    std::string buff;

    std::cout << "☎  PHONEBOOK" << std::endl << std::endl;
    std::cout << "Please enter one of the three following command" << std::endl << std::endl;
    std::cout << "ADD: Save a new contact" << std::endl;
    std::cout << "SEARCH: Display a specific contact" << std::endl;
    std::cout << "EXIT: The program quits and the contacts are lost forever!" << std::endl;
    std::cout << std::endl << "Waiting for a command ⚙️" << std::endl << "➜ ";
    std::getline(std::cin, buff);
    return(buff);
}

int check_arg(int argc)
{
    if (argc != 1)
    {
        std::cerr << "⚠️  No arguments allowed ⚠️" << std::endl;
        return (1);
    }
    return (0);
}

int check_input(std::string buff)
{
    if (buff != "ADD" && buff != "SEARCH" && buff != "EXIT")
    {
        std::cerr << "⚠️  WRONG ENTRY ⚠️" << std::endl << std::endl;
        return (1);
    }
    return (0);
}

void parse_input(std::string buff, Phonebook instance)
{
    if (buff == "ADD")
        instance.add_cmd();
    else if (buff == "SEARCH")
        instance.search_cmd();
    else if (buff == "EXIT")
        instance.exit_cmd();
}

int main(int argc, char **argv)
{
    Phonebook   instance;
    std::string buff;

    if (check_arg(argc) == 1)
        return(1);
    buff = prompt();
    while (check_input(buff) != 0)
        buff = prompt();
    parse_input(buff, instance);
    return (0);
}