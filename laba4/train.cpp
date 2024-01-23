// train.cpp
#include "train.h"

// ����������� �� ���������
TRAIN::TRAIN() : trainNumber(0) {}

// ����������� � �����������
TRAIN::TRAIN(std::string dest, int number, std::string time)
    : destination(dest), trainNumber(number), departureTime(time) {}

// ���������� ������� �������
std::string TRAIN::getDestination() const {
    return destination;
}

int TRAIN::getTrainNumber() const {
    return trainNumber;
}

std::string TRAIN::getDepartureTime() const {
    return departureTime;
}

// ���������� ��������� ���������� (>>)
std::istream& operator>>(std::istream& input, TRAIN& train) {
    std::cout << "������� ����� ����������: ";
    input >> train.destination;

    std::cout << "������� ����� ������: ";
    input >> train.trainNumber;

    std::cout << "������� ����� �����������: ";
    input >> train.departureTime;

    return input;
}

// ���������� ��������� ������� (<<)
std::ostream& operator<<(std::ostream& output, const TRAIN& train) {
    output << "����� ������: " << train.trainNumber << "\n����� ����������: " << train.destination
        << "\n����� �����������: " << train.departureTime << "\n";
    return output;
}
