#ifndef SIGN_H
#define SIGN_H

#include <iostream>
#include <string>

enum class Zodiac
{
    Aries,       // Овен
    Taurus,      // Телец
    Gemini,      // Близнецы
    Cancer,      // Рак
    Leo,         // Лев
    Virgo,       // Дева
    Libra,       // Весы
    Scorpio,     // Скорпион
    Sagittarius, // Стрелец
    Capricorn,   // Козерог
    Aquarius,    // Водолей
    Pisces       // Рыбы
};

// Преобразование enum в строку
std::string zodiacToString(Zodiac z);

// Преобразование строки/номера в enum
Zodiac zodiacFromString(const std::string &s);
Zodiac zodiacFromInt(int n);

// Вывод знаков Зодиака
void printZodiacList();

class SIGN
{
private:
    std::string lastName;  // фамилия
    std::string firstName; // имя
    Zodiac zodiac;         // знак зодиака
    int birthday[3];       // 0 – день, 1 – месяц, 2 – год

public:
    // Конструктор по умолчанию
    SIGN();

    // Конструктор с параметрами
    SIGN(const std::string &ln,
         const std::string &fn,
         Zodiac z,
         int day, int month, int year);

    // Конструктор копирования
    SIGN(const SIGN &other);

    // Деструктор
    ~SIGN();

    // Методы доступа
    const std::string &getLastName() const;
    void setLastName(const std::string &ln);

    const std::string &getFirstName() const;
    void setFirstName(const std::string &fn);

    Zodiac getZodiac() const;
    void setZodiac(Zodiac z);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setBirthday(int day, int month, int year);

    // Печать объекта
    void print() const;

    // Редактирование полей объекта
    void edit();

    // Сравнение по дате рождения
    bool isEarlierThan(const SIGN &other) const;

    // Вывод в поток
    friend std::ostream &operator<<(std::ostream &os, const SIGN &s);

    // Ввод из потока
    friend std::istream &operator>>(std::istream &is, SIGN &s);
};

#endif // SIGN_H
