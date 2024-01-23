#include "TextProcessor.h"
#include <sstream>
#include <algorithm>
#include <iostream>
std::vector<std::string> splitString(const std::string& str) {
    std::vector<std::string> words;
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>(),
        std::back_inserter(words));
    return words;
}

void processSentence(const std::string& sentence, int targetWordCount) {
    std::vector<std::string> words = splitString(sentence);

    if (words.size() == targetWordCount) {
        std::cout << sentence << '.' << std::endl;
    }
}
int countWordsInSentence(const std::string& sentence) {
    std::istringstream iss(sentence);
    int wordCount = 0;
    std::string word;
    while (iss >> word) {
        wordCount++;
    }
    return wordCount;
}

