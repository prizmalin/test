#include <stdexcept>
#include <iomanip>
#include <sstream>
#include "sign.h"

// Вспомогательные функции
static const char *ZODIAC_NAMES[] = {
    "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo",
    "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};

std::string zodiacToString(Zodiac z)
{
    return ZODIAC_NAMES[(int)z];
}

Zodiac zodiacFromInt(int n)
{
    if (n < 1 || n > 12)
        throw std::invalid_argument("\nInvalid zodiac index");

    return static_cast<Zodiac>(n - 1);
}

Zodiac zodiacFromString(const std::string &s)
{
    for (int i = 0; i < 12; i++)
        if (zodiacToString((Zodiac)i) == s)
            return (Zodiac)i;

    throw std::invalid_argument("\nInvalid zodiac name");
}

void printZodiacList()
{
    std::cout << "Available zodiac signs:\n";
    for (int i = 0; i < 12; i++)
    {
        std::cout << (i + 1) << " - " << ZODIAC_NAMES[i] << "\n";
    }
}

// Конструктор по умолчанию
SIGN::SIGN()
{
    lastName = "";
    firstName = "";
    zodiac = Zodiac::Aries;
    birthday[0] = birthday[1] = birthday[2] = 0;
    std::cout << "SIGN: default constructor\n";
}

// Конструктор с параметрами
SIGN::SIGN(const std::string &ln,
           const std::string &fn,
           Zodiac z,
           int day, int month, int year)
{
    lastName = ln;
    firstName = fn;
    zodiac = z;
    setBirthday(day, month, year);
    std::cout << "SIGN: parameterized constructor\n";
}

// Конструктор копирования
SIGN::SIGN(const SIGN &other)
{
    lastName = other.lastName;
    firstName = other.firstName;
    zodiac = other.zodiac;
    birthday[0] = other.birthday[0];
    birthday[1] = other.birthday[1];
    birthday[2] = other.birthday[2];
    std::cout << "SIGN: copy constructor\n";
}

// Деструктор
SIGN::~SIGN()
{
    std::cout << "SIGN: destructor\n";
}

// Методы доступа
const std::string &SIGN::getLastName() const { return lastName; }
void SIGN::setLastName(const std::string &ln) { lastName = ln; }

const std::string &SIGN::getFirstName() const { return firstName; }
void SIGN::setFirstName(const std::string &fn) { firstName = fn; }

Zodiac SIGN::getZodiac() const { return zodiac; }
void SIGN::setZodiac(Zodiac z) { zodiac = z; }

int SIGN::getDay() const { return birthday[0]; }
int SIGN::getMonth() const { return birthday[1]; }
int SIGN::getYear() const { return birthday[2]; }

// Установка даты с проверкой
void SIGN::setBirthday(int day, int month, int year)
{
    if (day < 1 || day > 31 || month < 1 || month > 12 || year <= 0)
        throw std::invalid_argument("\nInvalid date");

    birthday[0] = day;
    birthday[1] = month;
    birthday[2] = year;
}

// Вывод объекта
void SIGN::print() const
{
    std::cout << lastName << " " << firstName
              << ", " << zodiacToString(zodiac) << ", "
              << std::setw(2) << std::setfill('0') << birthday[0] << "."
              << std::setw(2) << std::setfill('0') << birthday[1] << "."
              << birthday[2] << "\n";
}

void SIGN::edit()
{
    std::string tmp;

    std::cout << "Last name (" << lastName << "): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        lastName = tmp;

    std::cout << "First name (" << firstName << "): ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
        firstName = tmp;

    printZodiacList();
    std::cout << "Zodiac (" << zodiacToString(zodiac) << ") [1-12]: ";
    std::getline(std::cin, tmp);
    if (!tmp.empty())
    {
        try
        {
            int n = std::stoi(tmp);
            zodiac = zodiacFromInt(n);
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "Birthday ("
              << std::setw(2) << std::setfill('0') << birthday[0] << "."
              << std::setw(2) << std::setfill('0') << birthday[1] << "."
              << birthday[2] << ") [d m y]: ";

    std::getline(std::cin, tmp);
    if (!tmp.empty())
    {
        std::istringstream iss(tmp);
        int d, m, y;
        if (!(iss >> d >> m >> y))
        {
            std::cout << "Invalid input format. Birthday not changed.\n";
        }
        else
        {
            try
            {
                setBirthday(d, m, y);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }
}

// Сравнение по дате рождения
bool SIGN::isEarlierThan(const SIGN &other) const
{
    if (birthday[2] != other.birthday[2])
        return birthday[2] < other.birthday[2];
    if (birthday[1] != other.birthday[1])
        return birthday[1] < other.birthday[1];
    return birthday[0] < other.birthday[0];
}

// Вывод в поток
std::ostream &operator<<(std::ostream &os, const SIGN &s)
{
    os << s.lastName << " "
       << s.firstName << ", "
       << zodiacToString(s.zodiac) << ", "
       << std::setw(2) << std::setfill('0') << s.birthday[0] << "."
       << std::setw(2) << std::setfill('0') << s.birthday[1] << "."
       << s.birthday[2];

    return os;
}

// Ввод из потока
std::istream &operator>>(std::istream &is, SIGN &s)
{
    std::cout << "Last name: ";
    is >> s.lastName;

    std::cout << "First name: ";
    is >> s.firstName;

    printZodiacList();
    int znum;
    std::cout << "Zodiac [1-12]: ";
    is >> znum;
    s.zodiac = zodiacFromInt(znum);

    int d, m, y;
    std::cout << "Birthday (day month year): ";
    is >> d >> m >> y;

    s.setBirthday(d, m, y);

    return is;
}
