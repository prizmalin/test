#include "include/filetask.h"
#include "include/sign_manager.h"
#include "include/utils.h"

int main()
{
    SignManager manager;

    bool running = true;
    bool taskLoop = false;

    while (running)
    {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Task 1\n";
        std::cout << "2. Task 2\n";
        std::cout << "3. Exit\n";

        int choice = readInt("\nSelect an option: ");

        switch (choice)
        {
        case 1:
        {
            taskLoop = true;
            while (taskLoop)
            {
                std::cout << "\n=== Task 1: SIGN Database ===\n";
                std::cout << "1. Add record\n";
                std::cout << "2. Add record at position\n";
                std::cout << "3. Remove record\n";
                std::cout << "4. Edit record\n";
                std::cout << "5. Show all records\n";
                std::cout << "6. Sort by birthday\n";
                std::cout << "7. Search by last name\n";
                std::cout << "8. Return to main menu\n";

                int c = readInt("\nSelect an option: ");

                switch (c)
                {
                case 1:
                {
                    SIGN s;
                    try
                    {
                        std::cin >> s;
                        manager.pushBack(s);
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }

                case 2:
                {
                    int pos = readInt("Enter position: ");

                    if (pos < 0 || pos > manager.getSize())
                    {
                        std::cout << "Error: Invalid index for insertion\n";
                        break;
                    }

                    SIGN s;
                    try
                    {
                        std::cin >> s;
                        manager.addAt(pos, s);
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }

                case 3:
                {
                    int pos = readInt("Enter index to remove: ");
                    try
                    {
                        manager.removeAt(pos);
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }

                case 4:
                {
                    int pos = readInt("Enter index: ");
                    try
                    {
                        manager.editAt(pos);
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }

                case 5:
                    manager.printAll();
                    break;

                case 6:
                    manager.sortByBirthday();
                    std::cout << "Sorted.\n";
                    break;

                case 7:
                {
                    std::string ln = readLine("Enter last name: ");
                    int idx = manager.findByLastName(ln);
                    if (idx == -1)
                    {
                        std::cout << "Entry not found.\n";
                    }
                    else
                    {
                        std::cout << "Found at index " << idx << ":\n";
                        manager.printOne(idx);
                    }
                    break;
                }

                case 8:
                    taskLoop = false;
                    break;

                default:
                    std::cout << "Invalid option.\n";
                }
            }
            break;
        }

        case 2:
        {
            taskLoop = true;
            while (taskLoop)
            {
                std::cout << "\n=== Task 2: File Processing ===\n";
                std::cout << "1. Process file\n";
                std::cout << "2. Return to main menu\n";

                int subChoice = readInt("\nSelect an option: ");

                switch (subChoice)
                {
                case 1:
                    runFileTask();
                    break;

                case 2:
                    taskLoop = false;
                    break;

                default:
                    std::cout << "Invalid option. Try again.\n";
                }
            }
            break;
        }

        case 3:
            running = false;
            break;

        default:
            std::cout << "Invalid option. Try again.\n";
        }
    }

    std::cout << "\nProgram finished.\n";
    return 0;
}
