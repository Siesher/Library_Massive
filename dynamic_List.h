#ifndef DLIST_H
#define DLIST_H

#include "process.h"
#include <iostream>
#include <bits/c++config.h>

// Шаблонный класс узла
template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Шаблонный класс списка
template<typename T>
class Dynamic_List {
private:
    Node<T>* head;
    std::size_t size;

public:
    Dynamic_List() : head(nullptr), size(0) {}


    ~Dynamic_List() {
        deleteList();
    }

    void initialize() {
        head = nullptr;
        size = 0;
    }

    void deleteList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    bool is_empty() const {
        return size == 0;
    }

    void add(const T& value, std::size_t index) {
        if (index > size) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            for (std::size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        ++size;
    }

    void remove(std::size_t index) {
        if (is_empty()) {
            std::cerr << "List is empty" << std::endl;
            return;
        }
        if (index >= size) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }

        Node<T>* toDelete = nullptr;
        if (index == 0) {
            toDelete = head;
            head = head->next;
        } else {
            Node<T>* current = head;
            for (std::size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
        }
        delete toDelete;
        --size;
    }

    void display() const {
        if (is_empty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
        std::cout << std::endl;
    }
};
#endif // DLIST_H