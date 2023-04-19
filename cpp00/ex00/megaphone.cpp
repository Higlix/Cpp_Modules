#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            std::string str = argv[i];
            for (int j = 0; str[j]; j++)
                str[j] = toupper(str[j]);
            std::cout << str;
        }
    }
    return (0);
}