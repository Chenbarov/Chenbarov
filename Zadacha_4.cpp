#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double ay, h;

    cout << "Задача 4. Расчет времени набора высоты\n";
    cout << "Введите вертикальное ускорение ay(м / с^2) : "; 
    cin >> ay;
    cout << "Введите высоту h(м) : "; 
    cin >> h;

    // Проверка корректности ввода
    if(ay <= 0 || h <= 0) {
        cout << "\nОшибка: Ускорение ay и высота h должны быть строго больше 0!\n";
    }
 else {
     // Формула h = 0.5 * ay * t^2 => t = sqrt(2 * h / ay)
     double t = sqrt((2.0 * h) / ay);
     cout << "\nВремя набора высоты t = " << fixed << setprecision(2) << t << " с\n";
    }

    return 0;
}
