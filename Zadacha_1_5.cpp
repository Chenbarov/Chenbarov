#include <iostream>
#include <vector>
#include <iomanip>

struct Tochka {
    double vremya;
    double x, y, z;
};

int main() {
    double vx = 30.0, vy_nachalnaya = 40.0, vz = 20.0; 
    double dt = 0.01, t_max = 5.0;
    double g = 9.8;

    int rezhim = 0;
    std::cout << "Viberite rezhim rascheta traektorii:\n"
        << "1 - S siloy tyazhesti (os' Y vertikal'naya)\n"
        << "2 - Bez sily tyazhesti (pryamolineynoe)\n"
        << "Vash vibor (1 ili 2): ";
    if (!(std::cin >> rezhim)) return 1;

    std::vector<Tochka> traektoriya;

    for (double t = 0.0; t <= t_max; t += dt) {
        double x = vx * t;
        double z = vz * t;
        double y = 0.0;

        if (rezhim == 1) {
            y = vy_nachalnaya * t - 0.5 * g * t * t;
            if (y < 0.0) {
                y = 0.0; 
                traektoriya.push_back({ t, x, y, z });
                break;
            }
        }
        else {
            y = vy_nachalnaya * t;
        }

        traektoriya.push_back({ t, x, y, z });
    }

    std::cout << "\n"
        << std::setw(8) << "Vremya"
        << std::setw(10) << "X"
        << std::setw(10) << "Y"
        << std::setw(10) << "Z" << "\n";

    for (const auto& p : traektoriya) {
        std::cout << std::setw(8) << p.vremya
            << std::setw(10) << p.x
            << std::setw(10) << p.y
            << std::setw(10) << p.z << "\n";
    }

    std::cout << "\nNazhmi Enter dlya vihoda...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}

