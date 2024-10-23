#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "process.h"

template<typename T>
class List {
private:
    T* data;
    std::size_t size;
    std::size_t capacity;

public:
    // Конструктор
    List(std::size_t N) : data(new T[N]), size(0), capacity(N) {}

    // Деструктор
    ~List() {
        delete[] data;
    }

    // Проверка на пустоту
    bool is_empty() const {
        return size == 0;
    }

    // Проверка на заполненность
    bool is_full() const {
        return size == capacity;
    }

    // Добавление элемента
    void add(const T& value, std::size_t index) {
        if (is_full()) {
            std::cerr << "List is full" << std::endl;
            std::cout << std::endl;
            return;
        }
        if (index >= capacity) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }
        for (std::size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    // Удаление элемента
    void remove(std::size_t index) {
        if (is_empty()) {
            std::cerr << "List is empty" << std::endl;
            return;
        }
        if (index >= size) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }
        for (std::size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    // Вывод списка
    void display() const {
        if (is_empty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        for (std::size_t i = 0; i < size; ++i) {
            std::cout << data[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // LIST_H
