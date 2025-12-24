#include "../include/sign_manager.h"
#include "../include/utils.h"
#include <iostream>
#include <stdexcept>

// Конструктор по умолчанию
SignManager::SignManager() : data(nullptr), size(0)
{
    std::cout << "\nSignManager created (default constructor)\n";
}

// Конструктор копирования
SignManager::SignManager(const SignManager &other) : data(nullptr), size(0)
{
    if (other.size > 0)
    {
        size = other.size;
        data = new SIGN[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    std::cout << "\nSignManager created (copy constructor)\n";
}

// Деструктор
SignManager::~SignManager()
{
    delete[] data;
    std::cout << "\nSignManager destroyed (destructor)\n";
}

// Оператор присваивания
SignManager &SignManager::operator=(const SignManager &other)
{
    if (this == &other)
        return *this;

    delete[] data;
    data = nullptr;
    size = 0;

    if (other.size > 0)
    {
        size = other.size;
        data = new SIGN[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    std::cout << "\nSignManager assigned (operator=)\n";
    return *this;
}

// Добавление в конец
void SignManager::pushBack(const SIGN &obj)
{
    SIGN *newData = new SIGN[size + 1];

    for (int i = 0; i < size; i++)
        newData[i] = data[i];

    newData[size] = obj;

    delete[] data;
    data = newData;
    size++;
}

// Вставка на позицию
void SignManager::addAt(int index, const SIGN &obj)
{
    if (index < 0 || index > size)
        throw std::out_of_range("\nInvalid index for insertion");

    SIGN *newData = new SIGN[size + 1];

    for (int i = 0; i < index; i++)
        newData[i] = data[i];

    newData[index] = obj;

    for (int i = index; i < size; i++)
        newData[i + 1] = data[i];

    delete[] data;
    data = newData;
    size++;
}

// Удаление по индексу
void SignManager::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("\nInvalid index for deletion");

    SIGN *newData = nullptr;

    if (size - 1 > 0)
        newData = new SIGN[size - 1];

    for (int i = 0; i < index; i++)
        newData[i] = data[i];

    for (int i = index + 1; i < size; i++)
        newData[i - 1] = data[i];

    delete[] data;
    data = newData;
    size--;
}

// Редактирование записи
void SignManager::editAt(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("\nInvalid index for editing");

    std::cout << "Editing record:\n";
    data[index].print();

    std::cout << "\nEnter new data:\n";
    std::cout << "(Leave lines empty to keep current)\n";
    data[index].edit();
}

// Вывод конкретного пользователя
void SignManager::printOne(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    data[index].print();
}

// Вывод всех записей
void SignManager::printAll() const
{
    if (size == 0)
    {
        std::cout << "\nNo records.\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] ";
        data[i].print();
    }
}

// Поиск по фамилии
int SignManager::findByLastName(const std::string &lastName) const
{
    std::string target = toLower(lastName);

    for (int i = 0; i < size; i++)
    {
        if (toLower(data[i].getLastName()) == target)
            return i;
    }
    return -1;
}

// Сортировка по дате рождения
void SignManager::sortByBirthday()
{
    if (size < 2)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (data[j + 1].isEarlierThan(data[j]))
                std::swap(data[j], data[j + 1]);
        }
    }
}
