#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double S, V, rho, C_L;

    cout << "Задача 1. Расчет подъемной силы\n";
    cout << "Введите площадь крыла S(м^2) :"; 
    cin >> S;
    cout << "Введите скорость полета V(м / с) : ";
    cin >> V;
    cout << "Введите плотность воздуха rho(кг / м³) : ";
    cin >> rho;
    cout << "Введите коэффициент подъемной силы C_L : ";
    cin >> C_L;

    // Формула: L = 0.5 * rho * V^2 * S * C_L
    double L = 0.5 * rho * V * V * S * C_L;

    cout << "\nПодъемная сила L = " << fixed << setprecision(2) << L << " Н\n";

    return 0;
}
