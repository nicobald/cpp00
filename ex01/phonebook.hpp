#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

    public:
        void        setFields(void);
        void        display(void) const;
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
};

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _count;
        int     _next;

    public:
        PhoneBook(void);
        void    add_cmd(void);
        void    search_cmd(void) const;
};

#endif
