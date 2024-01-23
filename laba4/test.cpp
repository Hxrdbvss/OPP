#include "test.h"
#include "train.h"
#include <cassert>
#include <iostream>
#include <sstream>

int test() {
    TRAIN Train("Москва", 123, "52:11");

    // Проверка вывода на экран
    std::cout << "Тест 1: Вывод на экран\n";
    std::cout << Train << std::endl;

    // Проверка ввода с клавиатуры
    TRAIN TrainInput;
    std::cout << "Тест 2: Ввод с клавиатуры\n";
    std::istringstream input("Москва\n52\n11\n");
    input >> TrainInput;
    std::cout << "\nМосква\n52\n11\n";

    // Используйте строковые значения для сравнения
    assert(TrainInput.getDestination() == "Москва");
    assert(TrainInput.getTrainNumber() == 52);
    assert(TrainInput.getDepartureTime() == "52:11");

    return 1;
}