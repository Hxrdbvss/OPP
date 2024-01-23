// main.cpp
#include <iostream>
#include "A.h"
#include "B.h"

int main() {
    try {
        // Создание объектов классов B и A
        B bObject;

        // Инстанцирование шаблона A для типа int
        A<int> aIntObject(&bObject);
        aIntObject.someMethod();

        // Инстанцирование шаблона A для типа double
        A<double> aDoubleObject(&bObject);
        aDoubleObject.someMethod();

        // Инстанцирование шаблона A для типа std::string
        A<std::string> aStringObject(&bObject);
        aStringObject.someMethod();

        // Пример ситуации, приводящей к генерации исключения
        A<int> negativeSizeObject(&bObject);  // Попытка создать объект A с отрицательным размером
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }

    return 0;
}
