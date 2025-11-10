#include "../include/program.h"
#include <iostream>

// Конструктор по умолчанию
Program::Program()
{
    std::cout << "Program object created (default constructor)\n";
}

// Конструктор с параметрами
Program::Program(const std::string &day, const std::string &t, const std::string &tit)
    : day(day), time(t), title(tit)
{
    std::cout << "Program object created (parameterized constructor)\n";
}

// Конструктор копирования
Program::Program(const Program &p)
    : day(p.day), time(p.time), title(p.title)
{
    std::cout << "Program object created (copy constructor)\n";
}

// Деструктор
Program::~Program()
{
    std::cout << "Program object destroyed (destructor)\n";
}

// Отображение информации о программе
void Program::Show() const
{
    std::cout << "PROGRAM - Day: " << day
              << " | Time: " << time
              << " | Title: " << title
              << "\n";
}

// Редактирование данных
void Program::Edit()
{
    std::string tmp;

    std::cout << "Enter new day (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        day = tmp;

    std::cout << "Enter new time (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        time = tmp;

    std::cout << "Enter new title (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        title = tmp;
}

// Сохранение данных в файл
void Program::Save(std::ofstream &file) const
{
    if (!file)
        throw std::runtime_error("File not open for writing");

    file << day << '\n'
         << time << '\n'
         << title << '\n';
}

// Загрузка данных из файла
void Program::Load(std::ifstream &file)
{
    if (!file)
        throw std::runtime_error("File not open for reading");

    std::getline(file, day);
    std::getline(file, time);
    std::getline(file, title);
}

// Возвращает новую копию объекта
Conference *Program::Clone() const
{
    return new Program(*this);
}

// Возвращает тип объекта
ConfType Program::Type() const
{
    return ConfType::PROGRAM;
}
