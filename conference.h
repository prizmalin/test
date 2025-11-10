#pragma once
#include <iostream>
#include <fstream>
#include <string>

// Перечисление типов объектов конференции
enum class ConfType
{
    SPEAKER,
    ADMIN,
    PROGRAM
};

// Абстрактный базовый класс Conference
class Conference
{
public:
    // Виртуальные методы для полиморфного взаимодействия
    virtual void Show() const = 0;
    virtual void Edit() = 0;
    virtual void Save(std::ofstream &file) const = 0;
    virtual void Load(std::ifstream &file) = 0;

    // Виртуальный деструктор для корректного удаления наследников
    virtual ~Conference() {}

    // Виртуальные методы для клонирования и определения типа
    virtual Conference *Clone() const = 0;
    virtual ConfType Type() const = 0;
};
