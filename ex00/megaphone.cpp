#include <iostream>
#include <string>

std::string to_upper(std::string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
    return s;
}

void print_arg(char **argv)
{
    int i;

    for (i = 1; argv[i]; i++)
    {
        std::cout << to_upper(argv[i]);
        if (argv[i + 1])
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        print_arg(argv);
    return (0);
}
