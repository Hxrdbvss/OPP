// main.cpp
#include <iostream>
#include "A.h"
#include "B.h"

int main() {
    try {
        // �������� �������� ������� B � A
        B bObject;

        // ��������������� ������� A ��� ���� int
        A<int> aIntObject(&bObject);
        aIntObject.someMethod();

        // ��������������� ������� A ��� ���� double
        A<double> aDoubleObject(&bObject);
        aDoubleObject.someMethod();

        // ��������������� ������� A ��� ���� std::string
        A<std::string> aStringObject(&bObject);
        aStringObject.someMethod();

        // ������ ��������, ���������� � ��������� ����������
        A<int> negativeSizeObject(&bObject);  // ������� ������� ������ A � ������������� ��������
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }

    return 0;
}
