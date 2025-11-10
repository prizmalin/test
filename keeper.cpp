#include "../include/keeper.h"
#include "../include/speaker.h"
#include "../include/admin.h"
#include "../include/program.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

// Конструктор по умолчанию
Keeper::Keeper() : data(nullptr), size(0)
{
    std::cout << "Keeper object created (default constructor)\n";
}

// Конструктор копирования
Keeper::Keeper(const Keeper &other)
{
    size = 0;
    data = nullptr;

    if (other.size > 0)
    {
        size = other.size;
        data = new Conference *[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i]->Clone();
        }
    }
    std::cout << "Keeper object created (copy constructor)\n";
}

// Деструктор
Keeper::~Keeper()
{
    if (data)
    {
        for (int i = 0; i < size; i++)
            delete data[i];
        delete[] data;
    }
    std::cout << "Keeper object destroyed (destructor)\n";
}

// Оператор =
Keeper &Keeper::operator=(const Keeper &other)
{
    if (this == &other)
        return *this;

    for (int i = 0; i < size; i++)
        delete data[i];
    delete[] data;
    data = nullptr;
    size = 0;

    if (other.size > 0)
    {
        size = other.size;
        data = new Conference *[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i]->Clone();
    }

    std::cout << "Keeper assigned (operator=)\n";
    return *this;
}

// Добавление нового объекта в контейнер
void Keeper::Add(Conference *obj)
{
    Conference **newData = new Conference *[size + 1];
    for (int i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }

    newData[size] = obj;
    delete[] data;
    data = newData;
    size++;
    std::cout << "Adding object (done). New size: " << size << "\n";
}

// Удаление объекта по индексу
void Keeper::Delete(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    delete data[index];
    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }

    if (size - 1 == 0)
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }
    else
    {
        Conference **newData = new Conference *[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size--;
    }
    std::cout << "Deleted object at index " << index << ". New size: " << size << "\n";
}

// Отображение всех объектов
void Keeper::ShowAll() const
{
    std::cout << "Showing all objects. Count: " << size << "\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] ";
        data[i]->Show();
    }
}

// Сохранение всех данных в файл
void Keeper::SaveToFile(const std::string &path) const
{
    std::ofstream fout(path);
    if (!fout)
    {
        throw std::runtime_error("Cannot open file for writing");
    }

    std::cout << "Saving to file \"" << path << "\"...\n";
    fout << size << '\n';

    for (int i = 0; i < size; i++)
    {
        ConfType t = data[i]->Type();
        if (t == ConfType::SPEAKER)
            fout << "SPEAKER\n";
        else if (t == ConfType::ADMIN)
            fout << "ADMIN\n";
        else
            fout << "PROGRAM\n";
        data[i]->Save(fout);
    }
}

// Загрузка всех данных из файла
void Keeper::LoadFromFile(const std::string &path)
{
    std::ifstream fin(path);
    if (!fin)
    {
        throw std::runtime_error("Cannot open file for reading");
    }

    // Очистка старых данных
    for (int i = 0; i < size; ++i)
    {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    size = 0;

    int count;
    fin >> count;
    fin.ignore();

    std::cout << "Loading " << count << " objects from file \"" << path << "\"...\n";

    for (int i = 0; i < count; ++i)
    {
        std::string type;
        std::getline(fin, type); // читаем тип объекта (SPEAKER, ADMIN, PROGRAM)

        Conference *obj = nullptr;

        if (type == "SPEAKER")
        {
            obj = new Speaker();
        }
        else if (type == "ADMIN")
        {
            obj = new Admin();
        }
        else if (type == "PROGRAM")
        {
            obj = new Program();
        }
        else
        {
            throw std::runtime_error("Unknown object type: " + type);
        }

        obj->Load(fin);
        Add(obj);
    }

    std::cout << "Loading completed successfully.\n";
}

void Keeper::EditByIndex(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");
    data[index]->Edit();
}
