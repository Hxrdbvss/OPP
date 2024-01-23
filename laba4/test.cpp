#include "test.h"
#include "train.h"
#include <cassert>
#include <iostream>
#include <sstream>

int test() {
    TRAIN Train("������", 123, "52:11");

    // �������� ������ �� �����
    std::cout << "���� 1: ����� �� �����\n";
    std::cout << Train << std::endl;

    // �������� ����� � ����������
    TRAIN TrainInput;
    std::cout << "���� 2: ���� � ����������\n";
    std::istringstream input("������\n52\n11\n");
    input >> TrainInput;
    std::cout << "\n������\n52\n11\n";

    // ����������� ��������� �������� ��� ���������
    assert(TrainInput.getDestination() == "������");
    assert(TrainInput.getTrainNumber() == 52);
    assert(TrainInput.getDepartureTime() == "52:11");

    return 1;
}