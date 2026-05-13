#include "List.h"
#include <iostream>

using namespace std;

// ============================================================
//                        СТЕК (LIFO)
// ============================================================

// Додавання елементу на вершину стеку
void push(Stack& s, datatype a) {
    Node* temp = new Node;
    temp->key = a;
    temp->next = s.head;
    s.head = temp;
}

// Видалення елементу з вершини стеку
void pop(Stack& s) {
    if (s.head == nullptr) {
        cout << "Помилка: стек порожній!" << endl;
        return;
    }
    Node* temp = s.head;
    s.head = s.head->next;
    delete temp;
}

// Вивід стеку (від вершини до дна)
void show(const Stack& s) {
    if (s.head == nullptr) {
        cout << "(стек порожній)" << endl;
        return;
    }
    Node* temp = s.head;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Звільнення всієї пам'яті стеку
void destroy(Stack& s) {
    while (s.head != nullptr) {
        Node* temp = s.head;
        s.head = s.head->next;
        delete temp;
    }
}

// ============================================================
//                       ЧЕРГА (FIFO)
// ============================================================

// Додавання елементу в кінець черги
void enqueue(Queue& q, datatype a) {
    Node* temp = new Node;
    temp->key = a;
    temp->next = nullptr;

    if (q.front == nullptr) {
        q.front = temp;
        q.back = temp;
    } else {
        q.back->next = temp;
        q.back = temp;
    }
}

// Видалення елементу з початку черги
void dequeue(Queue& q) {
    if (q.front == nullptr) {
        cout << "Помилка: черга порожня!" << endl;
        return;
    }
    Node* temp = q.front;
    q.front = q.front->next;
    if (q.front == nullptr) {
        q.back = nullptr;
    }
    delete temp;
}

// Вивід черги (від початку до кінця)
void show(const Queue& q) {
    if (q.front == nullptr) {
        cout << "(черга порожня)" << endl;
        return;
    }
    Node* temp = q.front;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Звільнення всієї пам'яті черги
void destroy(Queue& q) {
    while (q.front != nullptr) {
        Node* temp = q.front;
        q.front = q.front->next;
        delete temp;
    }
    q.back = nullptr;
}

// ============================================================
//                ДВОЗВ'ЯЗНИЙ ЛІНІЙНИЙ СПИСОК
// ============================================================

// Додавання елементу на початок списку
void add_begin(List& l, datatype a) {
    DNode* temp = new DNode;
    temp->key = a;
    temp->next = l.first;
    temp->previous = nullptr;

    if (l.first != nullptr) {
        l.first->previous = temp;
    } else {
        l.last = temp; // список був порожній
    }
    l.first = temp;
}

// Додавання елементу в кінець списку
void add_end(List& l, datatype a) {
    DNode* temp = new DNode;
    temp->key = a;
    temp->next = nullptr;
    temp->previous = l.last;

    if (l.last != nullptr) {
        l.last->next = temp;
    } else {
        l.first = temp; // список був порожній
    }
    l.last = temp;
}

// Видалення елементу з початку списку
void del_begin(List& l) {
    if (l.first == nullptr) {
        cout << "Помилка: список порожній!" << endl;
        return;
    }
    DNode* temp = l.first;
    l.first = l.first->next;
    if (l.first != nullptr) {
        l.first->previous = nullptr;
    } else {
        l.last = nullptr; // список спорожнів
    }
    delete temp;
}

// Видалення елементу з кінця списку
void del_end(List& l) {
    if (l.last == nullptr) {
        cout << "Помилка: список порожній!" << endl;
        return;
    }
    DNode* temp = l.last;
    l.last = l.last->previous;
    if (l.last != nullptr) {
        l.last->next = nullptr;
    } else {
        l.first = nullptr; // список спорожнів
    }
    delete temp;
}

// Пошук елементу за ключем, повертає вказівник на вузол або nullptr
DNode* search(const List& l, datatype a) {
    DNode* temp = l.first;
    while (temp != nullptr) {
        if (temp->key == a) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Додавання елементу ПІСЛЯ вузла зі знайденим ключем
void add_mid(List& l, datatype key, datatype value) {
    DNode* p = search(l, key);

    if (p == nullptr) {
        cout << "Елемент з ключем " << key << " не знайдено!" << endl;
        return;
    }

    // Якщо знайдений - останній, просто додаємо в кінець
    if (p == l.last) {
        add_end(l, value);
        return;
    }

    DNode* temp = new DNode;
    temp->key = value;
    temp->next = p->next;
    temp->previous = p;
    p->next->previous = temp;
    p->next = temp;
}

// Видалення вузла зі знайденим ключем
void del_mid(List& l, datatype key) {
    DNode* p = search(l, key);

    if (p == nullptr) {
        cout << "Елемент з ключем " << key << " не знайдено!" << endl;
        return;
    }

    if (p == l.first) {
        del_begin(l);
        return;
    }
    if (p == l.last) {
        del_end(l);
        return;
    }

    p->previous->next = p->next;
    p->next->previous = p->previous;
    delete p;
}

// Вивід списку (від першого до останнього)
void show(const List& l) {
    if (l.first == nullptr) {
        cout << "(список порожній)" << endl;
        return;
    }
    DNode* temp = l.first;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Звільнення всієї пам'яті списку
void destroy(List& l) {
    while (l.first != nullptr) {
        DNode* temp = l.first;
        l.first = l.first->next;
        delete temp;
    }
    l.last = nullptr;
}
