#include <iostream>
using namespace std;

int main()
{
    int choice;

    cout << "Choose lenguage of hello:" << endl;
    cout << "1 - Russian" << endl;
    cout << "2 - English" << endl;
    cout << "3 - Español" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Zdarova epta gandondddd!" << endl;
        break;
    case 2:
        cout << "Hello!" << endl;
        break;
    case 3:
        cout << "¡Hola!" << endl;
        break;
    default:
        cout << "Неизвестный выбор" << endl;
    }

    return 0;
}