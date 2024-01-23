// B.cpp
#include "B.h"

template <typename T>
void B::enqueue(T value) {
    if constexpr (std::is_same<T, int>::value) {
        intQueue.push(value);
    }
    else if constexpr (std::is_same<T, double>::value) {
        doubleQueue.push(value);
    }
    else if constexpr (std::is_same<T, std::string>::value) {
        stringQueue.push(value);
    }
}

template <typename T>
void B::dequeue() {
    if constexpr (std::is_same<T, int>::value) {
        if (!intQueue.empty()) {
            intQueue.pop();
        }
        else {
            throw std::runtime_error("Int Queue is empty");
        }
    }
    else if constexpr (std::is_same<T, double>::value) {
        if (!doubleQueue.empty()) {
            doubleQueue.pop();
        }
        else {
            throw std::runtime_error("Double Queue is empty");
        }
    }
    else if constexpr (std::is_same<T, std::string>::value) {
        if (!stringQueue.empty()) {
            stringQueue.pop();
        }
        else {
            throw std::runtime_error("String Queue is empty");
        }
    }
}

template <typename T>
void B::displayQueue() {
    if constexpr (std::is_same<T, int>::value) {
        std::cout << "Int Queue content: ";
        while (!intQueue.empty()) {
            std::cout << intQueue.front() << " ";
            intQueue.pop();
        }
        std::cout << std::endl;
    }
    else if constexpr (std::is_same<T, double>::value) {
        std::cout << "Double Queue content: ";
        while (!doubleQueue.empty()) {
            std::cout << doubleQueue.front() << " ";
            doubleQueue.pop();
        }
        std::cout << std::endl;
    }
    else if constexpr (std::is_same<T, std::string>::value) {
        std::cout << "String Queue content: ";
        while (!stringQueue.empty()) {
            std::cout << stringQueue.front() << " ";
            stringQueue.pop();
        }
        std::cout << std::endl;
    }
}

void B::performIntOperation(int data) {
    if (data < 0) {
        throw std::invalid_argument("Int operation requires non-negative data");
    }
    std::cout << "Performing int operation with data: " << data << std::endl;
}

void B::performDoubleOperation(double data) {
    if (data < 0) {
        throw std::invalid_argument("Double operation requires non-negative data");
    }
    std::cout << "Performing double operation with data: " << data << std::endl;
}

void B::performStringOperation(const std::string& data) {
    if (data.empty()) {
        throw std::invalid_argument("String operation requires non-empty data");
    }
    std::cout << "Performing string operation with data: " << data << std::endl;
}
