#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double G = 9.81;

struct Aircraft{
    string name;
    double mass;       // m
    double wing_area;  // S
    double thrust;     // T
    double C_L;
    double C_D;

    double lift;
    double drag;
    double accel_y;
    double climb_time;
};

int main() {
    setlocale(LC_ALL, "Russian");

    double rho = 1.225; // Плотность воздуха (кг/м³)
    double V = 100.0;   // Скорость полета (м/с)
    double h = 1000.0;  // Заданная высота (м)

    Aircraft planes[3];

    cout << "Задача 5. Сравнение трех конфигураций ЛА\n";

    for(int i = 0; i < 3; ++i) {
        planes[i].name = "Самолет №" + to_string(i + 1);
        cout << "\nВведите параметры для " << planes[i].name << ":\n";
        cout << "  Масса m(кг) : "; 
        cin >> planes[i].mass;
        cout << "  Площадь крыла S(м^2) : "; 
        cin >> planes[i].wing_area;
        cout << "  Тяга T(Н) : ";
        cin >> planes[i].thrust;
        cout << "  Коэффициент C_L : ";
        cin >> planes[i].C_L;
        cout << "  Коэффициент C_D : ";
        cin >> planes[i].C_D;

        // Расчеты
        planes[i].lift = 0.5 * rho * V * V * planes[i].wing_area * planes[i].C_L;
        planes[i].drag = 0.5 * rho * V * V * planes[i].wing_area * planes[i].C_D;
        planes[i].accel_y = (planes[i].lift - planes[i].mass * G) / planes[i].mass;

        if(planes[i].accel_y > 0) {
            planes[i].climb_time = sqrt((2.0 * h) / planes[i].accel_y);
        }
 else {
     planes[i].climb_time = -1.0; // Не может набрать высоту
        }
    }

    cout << "\nСводка результатов\n";
    int fastest_idx = -1;
    double min_time = 1e9;

    for(int i = 0; i < 3; ++i) {
        cout << planes[i].name << ": L = "<< planes[i].lift << " Н, D = " << planes[i].drag << " Н, ay = " << planes[i].accel_y << " м / с²";
        if(planes[i].climb_time > 0) {
            cout << ", Время t = " << planes[i].climb_time << " с\n";
            if(planes[i].climb_time < min_time) {
                min_time = planes[i].climb_time;
                fastest_idx = i;
            }
        }
 else {
     cout << ", Время: Невозможно набрать высоту\n";
        }
    }

    if(fastest_idx != -1) {
        cout << "\nПобедитель: " << planes[fastest_idx].name << " наберет высоту быстрее всех("<< min_time << " с).\n";
    }
 else {
     cout << "\nНи один самолет не смог подняться в воздух.\n";
    }

    return 0;
}
