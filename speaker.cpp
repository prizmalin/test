#include "../include/speaker.h"
#include <iostream>

// Конструктор по умолчанию
Speaker::Speaker()
{
    std::cout << "Speaker object created (default constructor)\n";
}

// Конструктор с параметрами
Speaker::Speaker(const std::string &n, const std::string &org, const std::string &rep, const std::string &ann)
    : name(n), organization(org), report(rep), annotation(ann)
{
    std::cout << "Speaker object created (parameterized constructor)\n";
}

// Конструктор копирования
Speaker::Speaker(const Speaker &s)
    : name(s.name), organization(s.organization), report(s.report), annotation(s.annotation)
{
    std::cout << "Speaker object created (copy constructor)\n";
}

// Деструктор
Speaker::~Speaker()
{
    std::cout << "Speaker object destroyed (destructor)\n";
}

// Отображение информации о выступающем
void Speaker::Show() const
{
    // Вывод всех полей
    std::cout << "SPEAKER - Name: " << name
              << " | Org: " << organization
              << " | Report: " << report
              << " | Annotation: " << annotation
              << "\n";
}

// Редактирование данных
void Speaker::Edit()
{
    std::string tmp;

    std::cout << "Enter new name (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        name = tmp;

    std::cout << "Enter new organization (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        organization = tmp;

    std::cout << "Enter new report title (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        report = tmp;

    std::cout << "Enter new annotation (or leave empty to keep current): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        annotation = tmp;
}

// Сохранение данных в файл
void Speaker::Save(std::ofstream &file) const
{
    if (!file)
        throw std::runtime_error("File not open for writing");

    file << name << '\n'
         << organization << '\n'
         << report << '\n'
         << annotation << '\n';
}

// Загрузка данных из файла
void Speaker::Load(std::ifstream &file)
{
    if (!file)
        throw std::runtime_error("File not open for reading");

    std::getline(file, name);
    std::getline(file, organization);
    std::getline(file, report);
    std::getline(file, annotation);
}

// Возвращает новую копию объекта
Conference *Speaker::Clone() const
{
    return new Speaker(*this);
}

// Возвращает тип объекта
ConfType Speaker::Type() const
{
    return ConfType::SPEAKER;
}
