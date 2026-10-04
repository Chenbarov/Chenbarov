#include <iostream>

using namespace std;

const double G = 9.81;

int main() {
    setlocale(LC_ALL, "Russian");

    double T, D, m, L;

    cout << " == = Задача 7. Автоматический выбор режима полета == = \n";
    cout << "Введите тягу T(Н) : "; 
    cin >> T;
    cout << "Введите сопротивление D(Н) : ";
    cin >> D;
    cout << "Bведите массу m(кг) : ";
    cin >> m;
    cout << "Введите подъемную силу L(Н) : ";
    cin >> L;

    // Вычисляем вертикальное ускорение
    double ay = (L - m * G) / m;

    cout << "\nРассчитанное вертикальное ускорение ay = " << ay << " м / с^2\n";

    // Условия выбора режима
    if(ay > 0.5) {
        cout << "Режим полета : Набор высоты\n";
    }
 else if (ay >= 0.0 && ay <= 0.5) {
     cout << "Режим полета : Горизонтальный полет\n";
    }
 else {
     cout << "Режим полета : Снижение\n";
    }

    return 0;
}


