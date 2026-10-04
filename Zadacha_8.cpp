#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const double G = 9.81;

struct Aircraft {
    string name;
    double mass = 0.0;
    double thrust = 0.0;
    double C_L = 0.0;
    double C_D = 0.0;
    double accel_y = 0.0;
    double climb_time = 0.0;
};

int main() {
    setlocale(LC_ALL, "Russian");

    int num_aircrafts = 0;
    double h = 0.0, S = 30.0, V = 100.0, rho = 1.225;

    cout << "=== Задача 8. Время набора высоты для массива самолетов ===\n";
    cout << "Введите количество самолетов: ";
    cin >> num_aircrafts;
    cout << "Введите целевую высоту h (м): ";
    cin >> h;

    if (num_aircrafts <= 0) {
        cout << "Количество самолетов должно быть больше 0.\n";
        return 0;
    }

    vector<Aircraft> fleet(num_aircrafts);

    for (int i = 0; i < num_aircrafts; ++i) {
        fleet[i].name = "Самолет #" + to_string(i + 1);
        cout << "\nПараметры для " << fleet[i].name << ":\n";
        cout << "  Масса m (кг): "; 
        cin >> fleet[i].mass;
        cout << "  Тяга T (Н): "; 
        cin >> fleet[i].thrust;
        cout << "  C_L: "; 
        cin >> fleet[i].C_L;
        cout << "  C_D: "; 
        cin >> fleet[i].C_D;

        if (fleet[i].mass <= 0) {
            fleet[i].accel_y = 0;
            fleet[i].climb_time = -1.0;
            continue;
        }

        double L = 0.5 * rho * V * V * S * fleet[i].C_L;
        fleet[i].accel_y = (L - fleet[i].mass * G) / fleet[i].mass;

        if (fleet[i].accel_y > 0 && h > 0) {
            fleet[i].climb_time = sqrt((2.0 * h) / fleet[i].accel_y);
        }
        else {
            fleet[i].climb_time = -1.0;
        }
    }

    // Сортировка по возрастанию времени
    sort(fleet.begin(), fleet.end(), [](const Aircraft& a, const Aircraft& b) {
        if (a.climb_time <= 0) return false;
        if (b.climb_time <= 0) return true;
        return a.climb_time < b.climb_time;
        });

    cout << "\n--- Результаты (отсортированы по времени набора высоты) ---\n";
    for (const auto& plane : fleet) {
        cout << plane.name << " | Вертикальное ускорение ay = " << plane.accel_y << " м/с² | Время: ";
        if (plane.climb_time > 0) {
            cout << plane.climb_time << " с\n";
        }
        else {
            cout << "Не поднимется (ay <= 0)\n";
        }
    }

    return 0;
}

