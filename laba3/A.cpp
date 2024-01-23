// A.cpp
#include "A.h"
#include "B.h"

template <typename T>
A<T>::A(B* bPtr) : bObject(bPtr) {}

template <typename T>
A<T>::~A() {}

template <typename T>
void A<T>::someMethod() {
    try {
        // Использование объекта класса B в методе класса A
        bObject->enqueue<T>(42);
        bObject->dequeue<T>();
        bObject->displayQueue<T>();

        // Дополнительные операции с элементами вектора elementsVector
        elementsVector.push_back(10);
        elementsVector.push_back(20);

        // Использование методов класса A для каждого типа данных
        performIntOperation(5);
        performDoubleOperation(3.14);
        performStringOperation("Hello");

        // Пример ситуации, приводящей к генерации исключения
        performIntOperation(-1);  // Попытка выполнить операцию с отрицательным числом
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in A::someMethod: " << e.what() << std::endl;
    }
}

template <typename T>
void A<T>::performIntOperation(T data) {
    try {
        bObject->performIntOperation(static_cast<int>(data));
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error in A::performIntOperation: " + std::string(e.what()));
    }
}

template <typename T>
void A<T>::performDoubleOperation(T data) {
    try {
        bObject->performDoubleOperation(static_cast<double>(data));
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error in A::performDoubleOperation: " + std::string(e.what()));
    }
}

template <typename T>
void A<T>::performStringOperation(const T& data) {
    try {
        bObject->performStringOperation(static_cast<std::string>(data));
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error in A::performStringOperation: " + std::string(e.what()));
    }
}
