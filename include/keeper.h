#pragma once
#include "conference.h"

// Класс Keeper — контейнер для хранения и управления объектами Conference
class Keeper
{
private:
    Conference **data; // динамический массив указателей на объекты Conference
    int size;          // текущее количество элементов в контейнере

public:
    // Конструкторы, оператор присваивания и деструктор
    Keeper();                               // конструктор по умолчанию
    Keeper(const Keeper &other);            // конструктор копирования
    Keeper &operator=(const Keeper &other); // оператор присваивания
    ~Keeper();                              // деструктор

    // Основные функции контейнера
    void Add(Conference *obj);                      // добавление нового объекта
    void Delete(int index);                         // удаление по индексу
    void ShowAll() const;                           // вывод всех объектов
    void EditByIndex(int index);                    // редактирование выбранного объекта
    void SaveToFile(const std::string &path) const; // сохранение всех данных в файл
    void LoadFromFile(const std::string &path);     // загрузка данных из файла

    // Получение количества объектов
    int Size() const { return size; }
};
