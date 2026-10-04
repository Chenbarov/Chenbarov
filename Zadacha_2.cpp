#include <iostream>
#include <iomanip>

using namespace std;

// Отдельная функция для расчета сопротивления по формуле: D = 0.5 * rho * V^2 * S * C_D
double calculate_drag(double rho, double V, double S, double C_D) {
    return 0.5 * rho * V * V * S * C_D;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double S, V, rho, C_D;

    cout << "Задача 2. Расчет аэродинамического сопротивления\n";
    cout << "Введите площадь крыла S(м^2) : ";
    cin >> S;
    cout << "Введите скорость полета V(м / с) : ";
    cin >> V;
    cout << "Введите плотность воздуха rho(кг / м^3) : ";
    cin >> rho;
    cout << "Введите коэффициент сопротивления C_D : ";
    cin >> C_D;

    double D = calculate_drag(rho, V, S, C_D);

    cout << "\nАэродинамическое сопротивление D = " << fixed << setprecision(2) << D << "Н\n";

    return 0;
}

