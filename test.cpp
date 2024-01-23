#include "test.h"
#include "FixedLengthStringArray.h"
#include <cassert>

void testSetElement() {
    FixedLengthStringArray array(3);
    array.setElement(0, "Test");
    assert(array.getElement(0) == "Test");
}

void testConcatenateArrays() {
    FixedLengthStringArray array1(3);
    FixedLengthStringArray array2(3);

    array1.setElement(0, "Hello");
    array1.setElement(1, " ");
    array1.setElement(2, "world");

    array2.setElement(0, "C++");
    array2.setElement(1, " is");
    array2.setElement(2, " awesome!");

    FixedLengthStringArray concatenatedArray = array1.concatenateArrays(array2);
    assert(concatenatedArray.getElement(0) == "HelloC++");
    assert(concatenatedArray.getElement(1) == "  is");
    assert(concatenatedArray.getElement(2) == "world awesome!");
}

bool runTests() {
    testSetElement();
    testConcatenateArrays();
    return true;
}
