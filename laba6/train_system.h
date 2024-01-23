#ifndef TRAIN_SYSTEM_H
#define TRAIN_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>

struct Train {
    int trainNumber;
    std::string destinationStation;
    std::string departureTime;
};

class TrainSystem {
private:
    std::vector<Train> trains;

public:
    void addTrain(int number, const std::string& destination, const std::string& time);
    void displayAllTrains() const;
    void displayTrainByNumber(int number) const;
    void displayTrainsBeforeStation(const std::string& station) const;
    void loadTrainsFromFile(const std::string& filename);
    const std::vector<Train>& getTrains() const {
        return trains;
    }
};

#endif // TRAIN_SYSTEM_H
