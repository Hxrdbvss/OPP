// train.h
#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>

class TRAIN {
private:
    std::string destination;
    int trainNumber;
    std::string departureTime;

public:
    // Конструкторы
    TRAIN();
    TRAIN(std::string dest, int number, std::string time);

    // Методы доступа
    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;

    // Перегруженные операторы извлечения и вставки
    friend std::istream& operator>>(std::istream& input, TRAIN& train);
    friend std::ostream& operator<<(std::ostream& output, const TRAIN& train);
};

#endif // TRAIN_H
