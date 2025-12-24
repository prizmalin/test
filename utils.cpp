#include <iostream>
#include <limits>
#include <cctype>
#include "utils.h"

// Приведение к нижнему регистру
std::string toLower(const std::string &s)
{
    std::string result = s;
    for (char &c : result)
    {
        c = std::tolower(c);
    }
    return result;
}

// Безопасный ввод числа
int readInt(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else
        {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Безопасный ввод строки
std::string readLine(const std::string &prompt)
{
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}
