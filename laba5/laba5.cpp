/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// Функция для разделения строки на слова
std::vector<std::string> splitString(const std::string& str) {
    std::vector<std::string> words;
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>(),
        std::back_inserter(words));
    return words;
}

// Функция для фильтрации предложений по количеству слов
void filterSentencesByWordCount(const std::string& filePath, int targetWordCount) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Разделить строку на предложения
        std::istringstream sentenceStream(line);
        std::string sentence;
        while (std::getline(sentenceStream, sentence, '.')) {
            // Разделить предложение на слова
            std::vector<std::string> words = splitString(sentence);

            // Проверить количество слов в предложении
            if (words.size() == targetWordCount) {
                std::cout << sentence << '.' << std::endl;
            }
        }
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string filePath = "C:/Users/glebs/OneDrive/Рабочий стол/oop/laba5/laba5/input.txt";  // Замените на фактический путь к файлу
    int targetWordCount;

    std::cout << "Введите желаемое количество слов в предложении: ";
    std::cin >> targetWordCount;

    filterSentencesByWordCount(filePath, targetWordCount);

    return 0;
}*/