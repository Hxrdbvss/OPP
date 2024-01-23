#include "train_system.h"
#include <fstream>

void TrainSystem::addTrain(int number, const std::string& destination, const std::string& time) {
    Train newTrain = { number, destination, time };
    trains.push_back(newTrain);
}

void TrainSystem::displayAllTrains() const {
    for (const auto& train : trains) {
        std::cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
            << "\tВремя отправления: " << train.departureTime << std::endl;
    }
}

void TrainSystem::displayTrainByNumber(int number) const {
    for (const auto& train : trains) {
        if (train.trainNumber == number) {
            std::cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
                << "\tВремя отправления: " << train.departureTime << std::endl;
            return;
        }
    }
    std::cout << "Поезд с номером " << number << " не найден." << std::endl;
}

void TrainSystem::displayTrainsBeforeStation(const std::string& station) const {
    for (const auto& train : trains) {
        if (train.destinationStation < station) {
            std::cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
                << "\tВремя отправления: " << train.departureTime << std::endl;
        }
    }
}

void TrainSystem::loadTrainsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int number;
        std::string destination, time;
        while (file >> number >> destination >> time) {
            addTrain(number, destination, time);
        }
        std::cout << "Данные успешно загружены из файла.\n";
    }
    else {
        std::cout << "Ошибка при открытии файла.\n";
    }
}
