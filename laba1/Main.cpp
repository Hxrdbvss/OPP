#include "FixedLengthStringArray.h"
#include <iostream>
#include "test.h"
#include <chrono>

using namespace std;
using namespace  chrono;

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

void displayMenu() {
     cout << "1. Установить элемент в массиве\n";
     cout << "2. Получить элемент из массива\n";
     cout << "3. Сцепить массивы\n";
     cout << "4. Объединить массивы\n";
     cout << "5. Вывести элемент\n";
     cout << "6. Вывести массив\n";
     cout << "0. Выход\n";
     cout << "Введите ваш выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
        int length = 5;
        FixedLengthStringArray array1(length);
        FixedLengthStringArray array2(length);
        if (runTests()) {
             cout << "Юнит-тесты пройдены успешно!" <<  endl;
        }
        else {
             cerr << "Юнит-тесты не пройдены!" <<  endl;
        }
        int choice;
        do {
            displayMenu();
             cin >> choice;

            switch (choice) {
            case 1: {
                { LogDuration input;
                int index;
                 string value;
                 cout << "Введите индекс: ";
                 cin >> index;
                 cout << "Введите значение: ";
                 cin >> value;
                array1.setElement(index, value);
                break;
                }
            }
            case 2: {
                int index;
                { LogDuration input;
                 cout << "Введите индекс: ";
                 cin >> index;
                 cout << "Элемент с индексом " << index << ": " << array1.getElement(index) <<  endl;
                break;
                }
            }
            case 3: {
                { LogDuration input;
                FixedLengthStringArray concatenatedArray = array1.concatenateArrays(array2);
                 cout << "Сцепленный массив: ";
                concatenatedArray.displayArray();
                break;
                }
            }
            case 4: {
                { LogDuration input;
                FixedLengthStringArray mergedArray = array1.mergeArrays(array2);
                 cout << "Объединенный массив: ";
                mergedArray.displayArray();
                break;
                }
            }
            case 5: {
                { LogDuration input;
                int index;
                 cout << "Введите индекс: ";
                 cin >> index;
                 cout << "Элемент с индексом " << index << ": ";
                array1.displayElement(index);
                break;
                }
            }
            case 6: {
                { LogDuration input;
                 cout << "Массив: ";
                array1.displayArray();
                break;
                }
            }
            case 0:
                { LogDuration input;
                 cout << "Выход из программы.\n";
                break;
                }
                default:
                 cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                
            }
        } while (choice != 0);

        return 0;
}
