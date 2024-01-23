#include "train_system.h"
#include "test.h"
#include <chrono>
using namespace std;

using namespace std::chrono;
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
int main() {
    {LogDuration input;
    setlocale(LC_ALL, "Russian");
    if (runTests()) {
        cout << "Юнит-тесты пройдены успешно!" << endl;
    }
    else {
        cout << "Юнит-тесты не пройдены!" << endl;
    }
    TrainSystem trainSystem;
    int choice;

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить поезд\n";
        cout << "2. Вывести информацию о всех поездах\n";
        cout << "3. Вывести информацию о поезде по номеру\n";
        cout << "4. Вывести информацию о поездах до указанной станции\n";
        cout << "5. Загрузить поезда из файла\n";
        cout << "0. Выйти\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int number;
            string destination, time;
            cout << "Введите номер поезда: ";
            cin >> number;
            cout << "Введите станцию назначения: ";
            cin >> destination;
            cout << "Введите время отправления: ";
            cin >> time;
            trainSystem.addTrain(number, destination, time);
            break;
        }
        case 2:
            cout << "\nИнформация о всех поездах:" << endl;
            trainSystem.displayAllTrains();
            break;
        case 3: {
            int number;
            cout << "Введите номер поезда: ";
            cin >> number;
            cout << "\nИнформация о поезде по номеру:" << endl;
            trainSystem.displayTrainByNumber(number);
            break;
        }
        case 4: {
            string station;
            cout << "Введите станцию назначения: ";
            cin >> station;
            cout << "\nИнформация о поездах до указанной станции:" << endl;
            trainSystem.displayTrainsBeforeStation(station);
            break;
        }
        case 5: {
            string filename;
            cout << "Введите имя файла с данными о поездах: ";
            cin >> filename;
            trainSystem.loadTrainsFromFile(filename);
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;
    }
}
