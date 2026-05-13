#include "List.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void printMenu() {
    cout << "\n========== МЕНЮ ==========" << endl;
    cout << "--- Стек (LIFO) ---" << endl;
    cout << "1.  push     - додати на вершину" << endl;
    cout << "2.  pop      - видалити з вершини" << endl;
    cout << "3.  show     - показати стек" << endl;
    cout << "--- Черга (FIFO) ---" << endl;
    cout << "4.  enqueue  - додати в кінець" << endl;
    cout << "5.  dequeue  - видалити з початку" << endl;
    cout << "6.  show     - показати чергу" << endl;
    cout << "--- Двозв'язний список ---" << endl;
    cout << "7.  add_begin - додати на початок" << endl;
    cout << "8.  add_end   - додати в кінець" << endl;
    cout << "9.  del_begin - видалити з початку" << endl;
    cout << "10. del_end   - видалити з кінця" << endl;
    cout << "11. add_mid   - вставити ПІСЛЯ елементу з ключем" << endl;
    cout << "12. del_mid   - видалити елемент за ключем" << endl;
    cout << "13. search    - знайти елемент за ключем" << endl;
    cout << "14. show      - показати список" << endl;
    cout << "0.  Вихід" << endl;
    cout << "Ваш вибір: ";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // Три ЛОКАЛЬНІ структури — жодних extern, жодних глобальних змінних
    Stack s;
    Queue q;
    List l;

    cout << "================================================" << endl;
    cout << " Лабораторна №4: Лінійні списки, стек, черга" << endl;
    cout << "================================================" << endl;

    int choice;
    datatype value, key;

    do {
        printMenu();
        if (!(cin >> choice)) {
            cout << "Помилка вводу!" << endl;
            break;
        }

        switch (choice) {
            // --- Стек ---
            case 1:
                cout << "Введіть значення: ";
                cin >> value;
                push(s, value);
                cout << "Додано до стеку." << endl;
                break;
            case 2:
                pop(s);
                break;
            case 3:
                cout << "Стек (від вершини): ";
                show(s);
                break;

            // --- Черга ---
            case 4:
                cout << "Введіть значення: ";
                cin >> value;
                enqueue(q, value);
                cout << "Додано до черги." << endl;
                break;
            case 5:
                dequeue(q);
                break;
            case 6:
                cout << "Черга (від початку): ";
                show(q);
                break;

            // --- Двозв'язний список ---
            case 7:
                cout << "Введіть значення: ";
                cin >> value;
                add_begin(l, value);
                break;
            case 8:
                cout << "Введіть значення: ";
                cin >> value;
                add_end(l, value);
                break;
            case 9:
                del_begin(l);
                break;
            case 10:
                del_end(l);
                break;
            case 11:
                cout << "Введіть ключ (після якого вставити) та значення: ";
                cin >> key >> value;
                add_mid(l, key, value);
                break;
            case 12:
                cout << "Введіть ключ для видалення: ";
                cin >> key;
                del_mid(l, key);
                break;
            case 13:
                cout << "Введіть ключ для пошуку: ";
                cin >> key;
                if (search(l, key) != nullptr) {
                    cout << "Елемент з ключем " << key << " знайдено." << endl;
                } else {
                    cout << "Елемент з ключем " << key << " не знайдено." << endl;
                }
                break;
            case 14:
                cout << "Список (від першого): ";
                show(l);
                break;

            case 0:
                cout << "Завершення роботи..." << endl;
                break;
            default:
                cout << "Невірний вибір!" << endl;
        }
    } while (choice != 0);

    // Звільняємо пам'ять усіх трьох структур перед виходом
    destroy(s);
    destroy(q);
    destroy(l);

    return 0;
}
