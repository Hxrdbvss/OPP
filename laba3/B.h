// B.h
#pragma once

#include <queue>
#include <iostream>
#include <stdexcept>

class B {
private:
    std::queue<int> intQueue;
    std::queue<double> doubleQueue;
    std::queue<std::string> stringQueue;

public:
    template <typename T>
    void enqueue(T value);

    template <typename T>
    void dequeue();

    template <typename T>
    void displayQueue();

    void performIntOperation(int data);
    void performDoubleOperation(double data);
    void performStringOperation(const std::string& data);
};
