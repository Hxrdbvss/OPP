#ifndef FIXED_LENGTH_STRING_ARRAY_H
#define FIXED_LENGTH_STRING_ARRAY_H

#include <vector>
#include <stdexcept>
using namespace std;
class FixedLengthStringArray {
private:
    int length;
     vector< string> array;

public:
    FixedLengthStringArray(int len);

    void checkIndex(int index) const;
    void setElement(int index, const  string& value);
     string getElement(int index) const;

    FixedLengthStringArray concatenateArrays(const FixedLengthStringArray& otherArray) const;
    FixedLengthStringArray mergeArrays(const FixedLengthStringArray& otherArray) const;

    void displayElement(int index) const;
    void displayArray() const;
};

#endif 
