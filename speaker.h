#pragma once
#include "conference.h"

// Класс Speaker — информация о выступающем
class Speaker : public Conference
{
private:
    std::string name;
    std::string organization;
    std::string report;
    std::string annotation;

public:
    // Конструкторы и деструктор
    Speaker();
    Speaker(const std::string &, const std::string &, const std::string &, const std::string &);
    Speaker(const Speaker &);
    ~Speaker();

    // Основные методы (виртуальные из базового класса)
    void Show() const override;
    void Edit() override;
    void Save(std::ofstream &file) const override;
    void Load(std::ifstream &file) override;

    Conference *Clone() const override;
    ConfType Type() const override;

    //Геттеры и сеттеры
    std::string GetName() const { return name; }
    void SetName(const std::string &n) { name = n; }

    std::string GetOrganization() const { return organization; }
    void SetOrganization(const std::string &org) { organization = org; }

    std::string GetReport() const { return report; }
    void SetReport(const std::string &r) { report = r; }

    std::string GetAnnotation() const { return annotation; }
    void SetAnnotation(const std::string &a) { annotation = a; }
};
