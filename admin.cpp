#include "admin.h"
#include <iostream>

// Конструктор по умолчанию
Admin::Admin()
{
    std::cout << "Admin object created (default constructor)\n";
}

// Конструктор с параметрами
Admin::Admin(const std::string &n, const std::string &pos, const std::string &resp)
    : name(n), position(pos), responsibility(resp)
{
    std::cout << "Admin object created (parameterized constructor)\n";
}

// Конструктор копирования
Admin::Admin(const Admin &a)
    : name(a.name), position(a.position), responsibility(a.responsibility)
{
    std::cout << "Admin object created (copy constructor)\n";
}

// Деструктор
Admin::~Admin()
{
    std::cout << "Admin object destroyed (destructor)\n";
}

// Отображение информации об администраторе
void Admin::Show() const
{
    std::cout << "ADMIN   - Name: " << name
              << " | Position: " << position
              << " | Responsibility: " << responsibility
              << "\n";
}

// Редактирование данных
void Admin::Edit()
{
    std::string tmp;

    std::cout << "Enter new name (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        name = tmp;

    std::cout << "Enter new position (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        position = tmp;

    std::cout << "Enter new responsibility (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        responsibility = tmp;
}

// Сохранение данных в файл
void Admin::Save(std::ofstream &file) const
{
    if (!file)
        throw std::runtime_error("File not open for writing");

    file << name << '\n'
         << position << '\n'
         << responsibility << '\n';
}

// Загрузка данных из файла
void Admin::Load(std::ifstream &file)
{
    if (!file)
        throw std::runtime_error("File not open for reading");

    std::getline(file, name);
    std::getline(file, position);
    std::getline(file, responsibility);
}

// Возвращает новую копию объекта
Conference *Admin::Clone() const
{
    return new Admin(*this);
}

// Возвращает тип объекта
ConfType Admin::Type() const
{
    return ConfType::ADMIN;
}
