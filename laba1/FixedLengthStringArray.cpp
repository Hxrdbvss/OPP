#include "FixedLengthStringArray.h"
#include <algorithm>
#include <iostream>

using namespace std;

FixedLengthStringArray::FixedLengthStringArray(int len) : length(len), array(len, "") {}

void FixedLengthStringArray::checkIndex(int index) const {
    if (index < 0 || index >= length) {
        throw  out_of_range("Index out of bounds");
    }
}

void FixedLengthStringArray::setElement(int index, const string& value) {
    checkIndex(index);
    array[index] = value;
}

 string FixedLengthStringArray::getElement(int index) const {
    checkIndex(index);
    return array[index];
}

FixedLengthStringArray FixedLengthStringArray::concatenateArrays(const FixedLengthStringArray& otherArray) const {
    if (otherArray.length != length) {
        throw  invalid_argument("Arrays must have the same length for concatenation");
    }

    FixedLengthStringArray result(length);
    for (int i = 0; i < length; ++i) {
        result.setElement(i, array[i] + otherArray.getElement(i));
    }
    return result;
}

FixedLengthStringArray FixedLengthStringArray::mergeArrays(const FixedLengthStringArray& otherArray) const {
    if (otherArray.length != length) {
        throw  invalid_argument("Arrays must have the same length for merging");
    }

    FixedLengthStringArray result(length);
    for (int i = 0; i < length; ++i) {
        result.setElement(i, array[i]);
    }

    for (int i = 0; i < length; ++i) {
        if ( find(result.array.begin(), result.array.end(), otherArray.getElement(i)) == result.array.end()) {
            result.setElement(i, otherArray.getElement(i));
        }
    }
    return result;
}

void FixedLengthStringArray::displayElement(int index) const {
    cout << getElement(index) <<  endl;
}

void FixedLengthStringArray::displayArray() const {
    for (const auto& element : array) {
         cout << element << " ";
    }
    cout <<  endl;
}
