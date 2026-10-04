#include <iostream>
#include <cmath>

using namespace std;

const double G = 9.81;

int main() {
    setlocale(LC_ALL, "Russian");

    double m = 0.0, S = 0.0, C_L = 0.0, h = 0.0, V = 0.0, rho = 0.0;
    double T_min = 0.0, T_max = 0.0, dT = 0.0;

    cout << "=== Задача 10. Минимизация времени набора высоты ===\n";
    cout << "Введите массу m (кг): "; cin >> m;
    cout << "Введите площадь крыла S (м^2): "; cin >> S;
    cout << "Введите C_L: "; cin >> C_L;
    cout << "Введите высоту h (м): "; cin >> h;
    cout << "Введите скорость V (м/с): "; cin >> V;
    cout << "Введите плотность воздуха rho (кг/м^3): "; cin >> rho;

    if (m <= 0) {
        cout << "\nОшибка: Масса должна быть больше 0!\n";
        return 0;
    }

    cout << "\nВведите диапазон изменения тяги:\n";
    cout << " Минимальная тяга T_min (Н): "; cin >> T_min;
    cout << " Максимальная тяга T_max (Н): "; cin >> T_max;
    cout << " Шаг dT (Н): "; cin >> dT;

    if (dT <= 0) {
        cout << "\nОшибка: Шаг dT должен быть больше 0!\n";
        return 0;
    }

    double L = 0.5 * rho * V * V * S * C_L;
    double ay = (L - m * G) / m;

    if (ay <= 0 || h <= 0) {
        cout << "\nОшибка: Подъемная сила меньше массы самолета (ay <= 0) или высота некорректна, взлет невозможен!\n";
        return 0;
    }

    double best_T = -1.0;
    double min_time = 1e9;

    cout << "\n--- Перебор вариантов тяги ---\n";
    for (double T_current = T_min; T_current <= T_max; T_current += dT) {
        // Время набора высоты по формуле движения с постоянным ускорением ay
        double t = sqrt((2.0 * h) / ay);

        cout << "Тяга T = " << T_current << " Н | ay = " << ay << " м/с^2 | Время t = " << t << " с\n";

        if (t < min_time) {
            min_time = t;
            best_T = T_current;
        }
    }

    if (best_T >= 0) {
        cout << "\nОптимальное значение тяги: " << best_T << " Н (минимальное время: " << min_time << " с)\n";
    }
    else {
        cout << "\nНе удалось рассчитать оптимальную тягу.\n";
    }

    return 0;
}
