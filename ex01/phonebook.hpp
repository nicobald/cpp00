#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
 
# include <iostream>
# include <string>

class Phonebook
{
    public:
        std::string *contact;

        void add_cmd(void) const;
        void search_cmd(void) const;
        void exit_cmd(void) const;
};

class Contact
{

};

#endif