/*#include <iostream>
#include <algorithm>

class TRAIN {
private:
    std::string destination;
    int trainNumber;
    std::string departureTime;

public:
    // Конструктор по умолчанию
    TRAIN() : trainNumber(0) {}

    // Constructor
    TRAIN(std::string dest, int number, std::string time)
        : destination(dest), trainNumber(number), departureTime(time) {}

    // Accessor methods
    std::string getDestination() const { return destination; }
    int getTrainNumber() const { return trainNumber; }
    std::string getDepartureTime() const { return departureTime; }

    // Overloaded extraction (>>)
    friend std::istream& operator>>(std::istream& input, TRAIN& train);

    // Overloaded insertion (<<)
    friend std::ostream& operator<<(std::ostream& output, const TRAIN& train);
};

// Overloaded extraction (>>)
std::istream& operator>>(std::istream& input, TRAIN& train) {
    std::cout << "Enter destination: ";
    input >> train.destination;

    std::cout << "Enter train number: ";
    input >> train.trainNumber;

    std::cout << "Enter departure time: ";
    input >> train.departureTime;

    return input;
}

// Overloaded insertion (<<)
std::ostream& operator<<(std::ostream& output, const TRAIN& train) {
    output << "Train Number: " << train.trainNumber << "\nDestination: " << train.destination
        << "\nDeparture Time: " << train.departureTime << "\n";
    return output;
}

int main() {
    const int arraySize = 3;
    TRAIN trainArray[arraySize];

    // Input data and sort by train number
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Enter details for Train " << i + 1 << ":\n";
        std::cin >> trainArray[i];
    }

    std::sort(trainArray, trainArray + arraySize, [](const TRAIN& a, const TRAIN& b) {
        return a.getTrainNumber() < b.getTrainNumber();
        });

    // Output sorted information
    std::cout << "\nSorted Train Information:\n";
    for (const auto& train : trainArray) {
        std::cout << train;
    }

    // Search for a train by number
    int searchNumber;
    std::cout << "\nEnter the train number to search: ";
    std::cin >> searchNumber;

    auto it = std::find_if(trainArray, trainArray + arraySize, [searchNumber](const TRAIN& train) {
        return train.getTrainNumber() == searchNumber;
        });

    // Display search result
    if (it != trainArray + arraySize) {
        std::cout << "\nTrain found:\n" << *it;
    }
    else {
        std::cout << "\nTrain with number " << searchNumber << " not found.\n";
    }

    return 0;
}*/
