#pragma once
#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string& str);
void processSentence(const std::string& sentence, int targetWordCount);
int countWordsInSentence(const std::string& sentence);