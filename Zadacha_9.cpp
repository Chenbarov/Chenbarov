#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aircraft {
    string name;
    double mass = 0.0;
    double wing_area = 0.0;
    double thrust = 0.0;
    double C_L = 0.0;
    double C_D = 0.0;
    double lift = 0.0;
    double drag = 0.0;
    double accel_x = 0.0;
};

int main() {
    setlocale(LC_ALL, "Russian");

    int num_configs = 0;
    double V = 0.0, rho = 0.0;

    cout << "=== Задача 9. Интерактивный расчет характеристик ===\n";
    cout << "Введите количество конфигураций N: ";
    cin >> num_configs;

    if (num_configs <= 0) {
        cout << "Ошибка: Количество конфигураций должно быть больше 0.\n";
        return 0;
    }

    cout << "Введите скорость полета V (м/с): "; 
    cin >> V;
    cout << "Введите плотность воздуха rho (кг/м^3): "; 
    cin >> rho;

    vector<Aircraft> configs(num_configs);
    int leader_idx = 0;
    double max_accel = -1e9;

    for (int i = 0; i < num_configs; ++i) {
        configs[i].name = "Конфигурация " + to_string(i + 1);
        cout << "\n" << configs[i].name << ":\n";
        cout << "  Масса m (кг): "; 
        cin >> configs[i].mass;
        cout << "  Площадь крыла S (м^2): "; 
        cin >> configs[i].wing_area;
        cout << "  Тяга T (Н): "; 
        cin >> configs[i].thrust;
        cout << "  C_L: "; 
        cin >> configs[i].C_L;
        cout << "  C_D: "; 
        cin >> configs[i].C_D;

        if (configs[i].mass <= 0) {
            configs[i].accel_x = -1e9;
            continue;
        }

        configs[i].lift = 0.5 * rho * V * V * configs[i].wing_area * configs[i].C_L;
        configs[i].drag = 0.5 * rho * V * V * configs[i].wing_area * configs[i].C_D;
        configs[i].accel_x = (configs[i].thrust - configs[i].drag) / configs[i].mass;

        // Определение лидера по ускорению
        if (configs[i].accel_x > max_accel) {
            max_accel = configs[i].accel_x;
            leader_idx = i;
        }
    }

    cout << "\n--- Сводка по всем конфигурациям ---\n";
    for (int i = 0; i < num_configs; ++i) {
        cout << configs[i].name
            << " | Подъемная сила: " << configs[i].lift << " Н"
            << " | Сопротивление: " << configs[i].drag << " Н"
            << " | Ускорение a: " << configs[i].accel_x << " м/с^2\n";
    }

    cout << "\nЛидер по ускорению: " << configs[leader_idx].name
        << " с максимальным ускорением a = " << max_accel << " м/с²\n";

    return 0;
}
