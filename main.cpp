#include <iostream>
#include <limits>
#include "include/keeper.h"
#include "include/speaker.h"
#include "include/admin.h"
#include "include/program.h"

// Вспомогательные функции безопасного ввода

// Безопасное чтение целого числа с обработкой ошибок ввода
int readInt(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else
        {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Безопасное чтение строки
std::string readLine(const std::string &prompt)
{
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

// Основная функция программы
int main()
{
    Keeper keeper; // контейнер для хранения объектов
    bool running = true;

    while (running)
    {
        // Главное меню
        std::cout << "\nConference Management Menu\n";
        std::cout << "1. Add object\n";
        std::cout << "2. Delete object\n";
        std::cout << "3. Edit object\n";
        std::cout << "4. Show all objects\n";
        std::cout << "5. Save to file\n";
        std::cout << "6. Load from file\n";
        std::cout << "7. Exit\n";

        int choice = readInt("Select an option: ");

        // Обработка выбора пользователя
        switch (choice)
        {
        // Добавление нового объекта
        case 1:
        {
            std::cout << "\nSelect object type to add:\n";
            std::cout << "1. Speaker\n";
            std::cout << "2. Admin\n";
            std::cout << "3. Program\n";
            int type = readInt("Your choice: ");

            Conference *obj = nullptr;

            if (type == 1)
            {
                std::string name = readLine("Enter name: ");
                std::string org = readLine("Enter organization: ");
                std::string rep = readLine("Enter report: ");
                std::string ann = readLine("Enter annotation: ");
                obj = new Speaker(name, org, rep, ann);
            }
            else if (type == 2)
            {
                std::string name = readLine("Enter name: ");
                std::string pos = readLine("Enter position: ");
                std::string resp = readLine("Enter responsibility: ");
                obj = new Admin(name, pos, resp);
            }
            else if (type == 3)
            {
                std::string day = readLine("Enter day: ");
                std::string time = readLine("Enter time: ");
                std::string title = readLine("Enter title: ");
                obj = new Program(day, time, title);
            }
            else
            {
                std::cout << "Invalid type.\n";
                break;
            }

            keeper.Add(obj);
            std::cout << "Object added successfully.\n";
            break;
        }

        // Удаление объекта по индексу
        case 2:
        {
            int idx = readInt("\nEnter index to delete: ");
            try
            {
                keeper.Delete(idx);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << "\n";
            }
            break;
        }

        // Редактирование существующего объекта
        case 3:
        {
            int idx = readInt("\nEnter index to edit: ");
            if (idx < 0 || idx >= keeper.Size())
            {
                std::cout << "Invalid index.\n";
                break;
            }

            keeper.ShowAll();
            std::cout << "Editing object #" << idx << "...\n";

            try
            {
                keeper.EditByIndex(idx);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << "\n";
            }

            break;
        }

        // Отображение всех объектов
        case 4:
            std::cout << "\n";
            keeper.ShowAll();
            break;

        // Сохранение данных в файл
        case 5:
        {
            std::string path = readLine("\nEnter file name to save: ");
            try
            {
                keeper.SaveToFile(path);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << "\n";
            }
            break;
        }

        // Загрузка данных из файла
        case 6:
        {
            std::string path = readLine("\nEnter file name to load: ");
            try
            {
                keeper.LoadFromFile(path);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << "\n";
            }
            break;
        }

        // Завершение работы программы
        case 7:
            running = false;
            break;

        // Неверный пункт меню
        default:
            std::cout << "\nInvalid option. Try again.\n";
        }
    }

    std::cout << "\nProgram finished.\n\n";
    return 0;
}
