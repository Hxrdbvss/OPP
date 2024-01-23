// test.cpp
#include "test.h"
#include "TextProcessor.h"
#include <cassert>
#include <iostream>

bool testCountWordsInSentence() {
    std::string sentence1 = "This is test.";
    int wordCount1 = countWordsInSentence(sentence1);
    assert(wordCount1 == 3);
    return true;
}

