#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;


template <typename T>
class Vector {
private:
    int size;      // Размер вектора
    T* elements;   // Динамически выделенный массив объектов

public:
    // Конструкторы
    Vector(int n = 0) {
        size = n;
        elements = new T[size];
    }

    Vector(const Vector<T>& other) {
        size = other.size;
        elements = new T[size];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
   
    
    // Деструктор
    ~Vector() {
        delete[] elements;
    }
    //Оператор сложения
    Vector<T> operator+(const Vector<T>& other) const {
        if (size != other.size) {
             throw  "Error: Cannot add vectors with different sizes";
            exit(1); // Завершение программы с ненулевым кодом ошибки
        }

        Vector<T> result(size);
        for (int i = 0; i < size; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }
    //Оператор вычитания
    Vector<T>operator-(const Vector<T>& other) const {
        if (size != other.size) {
            cerr << "Error: Cannot subtract vectors with different sizes" << endl;
            exit(1); // Завершение программы с ненулевым кодом ошибки
        }
        Vector<T> result(size);
        for (int i = 0; i < size; i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }
    // Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] elements;
            size = other.size;
            elements = new T[size];
            for (int i = 0; i < size; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Методы доступа
    int getSize() const {
        return size;
    }

    T getElement(int index) const {
        return elements[index];
    }

    void setElement(int index, const T& value) {
        elements[index] = value;
    }
    double Lenght()const {
        double res = 0;
        for (int i = 0; i < size; i++) {
            res += elements[i] * elements[i];
        }
        res = sqrt(res);
        return res;
    }
    T operator*(const Vector<T>& vec) {
        if (vec.getSize() != size) {
            throw std::invalid_argument("Invalid vector dimensions! The vectors must have the same size.");
        }

        T result = 0;
        for (int i = 0; i < vec.getSize(); i++) {
            result += vec.getElement(i) * this->getElement(i);
        }

        return result;
    }


    bool operator==(const Vector<T>& obj)const {
        int flag = 0;
        if (size != obj.size)
            throw;
        for (int i = 0; i < size; i++) {
            if (elements[i] != obj.vec[i]) {
                flag++;
                break;
            }
        }
        if (flag == 0)
            return true;
        return false;
    }
    bool operator!=(const Vector<T>& obj)const {
        return !(this == obj);
    }
    // Перегрузка операторов ввода и вывода
    template <typename U>
    friend ostream& operator<<(ostream& os, const Vector<U>& vec);

    template <typename U>
    friend istream& operator>>(istream& is, Vector<U>& vec);
};

// Перегрузка оператора вывода
template <typename T>
ostream& operator<<(ostream& os, const Vector<T>& vec) {
    for (int i = 0; i < vec.getSize(); i++) {
        os << vec.getElement(i) << " ";
    }
    return os;
}

// Перегрузка оператора ввода
template <typename T>
istream& operator>>(istream& is, Vector<T>& vec) {
    cout << "Input vector ";
    for (int i = 0; i < vec.getSize(); i++) {
        is >> vec.elements[i];
    }
    return is;
}
