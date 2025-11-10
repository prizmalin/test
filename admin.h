#pragma once
#include "conference.h"

// Класс Admin — информация об администраторе конференции
class Admin : public Conference
{
private:
    std::string name;
    std::string position;
    std::string responsibility;

public:
    // Конструкторы и деструктор
    Admin();
    Admin(const std::string &, const std::string &, const std::string &);
    Admin(const Admin &);
    ~Admin();

    // Основные методы (виртуальные из базового класса)
    void Show() const override;
    void Edit() override;
    void Save(std::ofstream &file) const override;
    void Load(std::ifstream &file) override;

    Conference *Clone() const override;
    ConfType Type() const override;

    // Геттеры и сеттеры
    std::string GetName() const { return name; }
    void SetName(const std::string &n) { name = n; }

    std::string GetPosition() const { return position; }
    void SetPosition(const std::string &p) { position = p; }

    std::string GetResponsibility() const { return responsibility; }
    void SetResponsibility(const std::string &r) { responsibility = r; }
};
