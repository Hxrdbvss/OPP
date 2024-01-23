// FileHandler.cpp
#include "FileHandler.h"
#include <iostream>
#include <fstream>

std::string readFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    file.close();
    return content;
}
