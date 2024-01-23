// A.h
#pragma once

#include "B.h"
#include <vector>
#include <stdexcept>

class B;

template <typename T>
class A {
private:
    std::vector<T> elementsVector;
    B* bObject;

public:
    A(B* bPtr);
    ~A();
    void someMethod();

    void performIntOperation(T data);
    void performDoubleOperation(T data);
    void performStringOperation(const T& data);
};
