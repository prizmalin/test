#ifndef SIGN_MANAGER_H
#define SIGN_MANAGER_H

#include "sign.h"

// Класс-контейнер для управления динамическим массивом SIGN
class SignManager
{
private:
    SIGN *data; // массив объектов
    int size;   // размер массива

public:
    // Конструкторы и деструктор
    SignManager();
    SignManager(const SignManager &other);
    ~SignManager();

    SignManager &operator=(const SignManager &other);

    // Методы работы с массивом
    int getSize() const { return size; }

    void addAt(int index, const SIGN &obj);
    void pushBack(const SIGN &obj);
    void removeAt(int index);
    void editAt(int index);
    void printOne(int index) const;
    void printAll() const;

    // Поиск по фамилии
    int findByLastName(const std::string &lastName) const;

    // Сортировка по дате рождения
    void sortByBirthday();
};

#endif // SIGN_MANAGER_H
