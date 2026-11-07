#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct DannyeRakety {
    double v0;
    double max_h;
    double t_max_h;
    double t_fall;
};

DannyeRakety rasschitat_raketu(double v0, double g, double dt) {
    std::vector<double> times;
    std::vector<double> heights;

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0 && t > 0.1) {
            times.push_back(t);
            heights.push_back(0.0);
            break;
        }
        times.push_back(t);
        heights.push_back(h);
        if (v0 <= 0.0) break;
    }

    auto max_it = std::max_element(heights.begin(), heights.end());
    size_t max_idx = std::distance(heights.begin(), max_it);

    return { v0, *max_it, times[max_idx], times.back() };
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    double g = 9.8;
    double dt = 0.01;
    double v0_1 = 0.0, v0_2 = 0.0;

    std::cout << "Vvedite nachalnuyu skorost' 1-y rakety (m/s): ";
    if (!(std::cin >> v0_1)) return 1;

    std::cout << "Vvedite nachalnuyu skorost' 2-y rakety (m/s): ";
    if (!(std::cin >> v0_2)) return 1;

    DannyeRakety r1 = rasschitat_raketu(v0_1, g, dt);
    DannyeRakety r2 = rasschitat_raketu(v0_2, g, dt);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nRezultaty dlya rakety 1:\n";
    std::cout << " V0: " << r1.v0 << " m/s\n";
    std::cout << " Maks. vysota: " << r1.max_h << " m (v " << r1.t_max_h << " sek)\n";
    std::cout << " Vremya poleta: " << r1.t_fall << " sek\n";

    std::cout << "\nRezultaty dlya rakety 2:\n";
    std::cout << " V0: " << r2.v0 << " m/s\n";
    std::cout << " Maks. vysota: " << r2.max_h << " m (v " << r2.t_max_h << " sek)\n";
    std::cout << " Vremya poleta: " << r2.t_fall << " sek\n";

    std::cout << "\nSravnenie:\n";
    if (r1.max_h > r2.max_h) {
        std::cout << "Pervaya raketa vzletela vyshe na " << (r1.max_h - r2.max_h) << " m.\n";
    }
    else if (r2.max_h > r1.max_h) {
        std::cout << "Vtoraya raketa vzletela vyshe na " << (r2.max_h - r1.max_h) << " m.\n";
    }
    else {
        std::cout << "Obe rakety dostigli odinakovoy vysoty.\n";
    }

    if (r1.t_fall > r2.t_fall) {
        std::cout << "Pervaya raketa dolshe byla v vozduhe na " << (r1.t_fall - r2.t_fall) << " sek.\n";
    }
    else if (r2.t_fall > r1.t_fall) {
        std::cout << "Vtoraya raketa dolshe byla v vozduhe na " << (r2.t_fall - r1.t_fall) << " sek.\n";
    }
    else {
        std::cout << "Obe rakety proveli v polete odinakovoe vremya.\n";
    }

    std::cout << "\nNazhmi Enter dlya vihoda...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}