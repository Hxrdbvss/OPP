// main.cpp
#include <iostream>
#include <algorithm>
#include <chrono>
#include "train.h"
using namespace std;
using namespace std::chrono;

class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }
private:
    steady_clock::time_point start;
};
int main() {
    { LogDuration input;
    setlocale(LC_ALL, "Russian");
    const int arraySize = 3;
    TRAIN trainArray[arraySize];

    // ���� ������ � ���������� �� ������� �������
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "������� ������ ��� ������ " << i + 1 << ":\n";
        std::cin >> trainArray[i];
    }

    std::sort(trainArray, trainArray + arraySize, [](const TRAIN& a, const TRAIN& b) {
        return a.getTrainNumber() < b.getTrainNumber();
        });

    // ����� ��������������� ����������
    std::cout << "\n��������������� ���������� � �������:\n";
    for (const auto& train : trainArray) {
        std::cout << train;
    }

    // ����� ������ �� ������
    int searchNumber;
    std::cout << "\n������� ����� ������ ��� ������: ";
    std::cin >> searchNumber;

    auto it = std::find_if(trainArray, trainArray + arraySize, [searchNumber](const TRAIN& train) {
        return train.getTrainNumber() == searchNumber;
        });

    // ����� ���������� ������
    if (it != trainArray + arraySize) {
        std::cout << "\n����� ������:\n" << *it;
    }
    else {
        std::cout << "\n����� � ������� " << searchNumber << " �� ������.\n";
    }

    return 0;
    }

}