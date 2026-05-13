#pragma once

// Тип ключа елементу
typedef int datatype;

// Вузол для стеку та черги (однозв'язний)
struct Node {
    datatype key;
    Node* next;
};

// Вузол для двозв'язного списку
struct DNode {
    datatype key;
    DNode* next;
    DNode* previous;
};

// Стек (LIFO) — обгортка зі своїм head
struct Stack {
    Node* head;
    Stack() : head(nullptr) {}
};

// Черга (FIFO) — обгортка з front і back
struct Queue {
    Node* front;
    Node* back;
    Queue() : front(nullptr), back(nullptr) {}
};

// Двозв'язний список — обгортка з first і last
struct List {
    DNode* first;
    DNode* last;
    List() : first(nullptr), last(nullptr) {}
};

// === Операції над стеком ===
void push(Stack& s, datatype a);
void pop(Stack& s);
void show(const Stack& s);
void destroy(Stack& s);

// === Операції над чергою ===
void enqueue(Queue& q, datatype a);
void dequeue(Queue& q);
void show(const Queue& q);
void destroy(Queue& q);

// === Операції над двозв'язним списком ===
void add_begin(List& l, datatype a);
void add_end(List& l, datatype a);
void del_begin(List& l);
void del_end(List& l);
DNode* search(const List& l, datatype a);
void add_mid(List& l, datatype key, datatype value);
void del_mid(List& l, datatype key);
void show(const List& l);
void destroy(List& l);
