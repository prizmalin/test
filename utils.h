#ifndef UTILS_H
#define UTILS_H

#include <string>

// Приведение к нижнему регистру
std::string toLower(const std::string &s);

// Безопасный ввод числа
int readInt(const std::string &prompt);

// Безопасный ввод строки
std::string readLine(const std::string &prompt);

#endif