#pragma once
#include "conference.h"

// Класс Program — информация о программе конференции
class Program : public Conference
{
private:
    std::string day;
    std::string time;
    std::string title;

public:
    // Конструкторы и деструктор
    Program();
    Program(const std::string &, const std::string &, const std::string &);
    Program(const Program &);
    ~Program();

    // Основные методы (виртуальные из базового класса)
    void Show() const override;
    void Edit() override;
    void Save(std::ofstream &file) const override;
    void Load(std::ifstream &file) override;

    Conference *Clone() const override;
    ConfType Type() const override;

    // Геттеры и сеттеры
    std::string GetDay() const { return day; }
    void SetDay(const std::string &d) { day = d; }

    std::string GetTime() const { return time; }
    void SetTime(const std::string &t) { time = t; }

    std::string GetTitle() const { return title; }
    void SetTitle(const std::string &t) { title = t; }
};
