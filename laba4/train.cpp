// train.cpp
#include "train.h"

// Конструктор по умолчанию
TRAIN::TRAIN() : trainNumber(0) {}

// Конструктор с параметрами
TRAIN::TRAIN(std::string dest, int number, std::string time)
    : destination(dest), trainNumber(number), departureTime(time) {}

// Реализация методов доступа
std::string TRAIN::getDestination() const {
    return destination;
}

int TRAIN::getTrainNumber() const {
    return trainNumber;
}

std::string TRAIN::getDepartureTime() const {
    return departureTime;
}

// Реализация оператора извлечения (>>)
std::istream& operator>>(std::istream& input, TRAIN& train) {
    std::cout << "Введите пункт назначения: ";
    input >> train.destination;

    std::cout << "Введите номер поезда: ";
    input >> train.trainNumber;

    std::cout << "Введите время отправления: ";
    input >> train.departureTime;

    return input;
}

// Реализация оператора вставки (<<)
std::ostream& operator<<(std::ostream& output, const TRAIN& train) {
    output << "Номер поезда: " << train.trainNumber << "\nПункт назначения: " << train.destination
        << "\nВремя отправления: " << train.departureTime << "\n";
    return output;
}
