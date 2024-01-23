#include "FileHandler.h"
#include "TextProcessor.h"
#include "test.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
using namespace std;

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
    {LogDuration input;
        setlocale(LC_ALL, "Russian");
    if (testCountWordsInSentence()) {
        cout << "Юнит-тесты пройдены успешно!" << endl;
    }
    else {
        cerr << "Юнит-тесты не пройдены!" << endl;
    }

    std::string filePath = "C:/Users/glebs/OneDrive/Рабочий стол/oop/laba5/laba5/input.txt";
    int targetWordCount;

    std::cout << "Введите желаемое количество слов в предложении: ";
    std::cin >> targetWordCount;

    std::string fileContent = readFromFile(filePath);
    bool foundSuitableSentences = false;
    if (!fileContent.empty()) {
        std::istringstream sentenceStream(fileContent);
        std::string sentence;
        while (std::getline(sentenceStream, sentence, '.')) {
            processSentence(sentence, targetWordCount);
        }
    }
    else {
        cout << "Файл пустой. Нет данных для обработки." << endl;
    }
    return 0; 
    }
}
