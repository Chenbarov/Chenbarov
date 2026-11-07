#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    double v0 = 0.0;
    double g = 9.8;
    double dt = 0.01;

    std::cout << "Vvedite nachalnuyu skorost' rakety (v0, m/s): ";
    if (!(std::cin >> v0)) return 1;

    double t_fall = 0.0;
    double h_fall = 0.0;
    double v_fall = 0.0;

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;

        if (h <= 0.0 && t > 0.1) {
            t_fall = t;
            h_fall = h; 
            v_fall = v0 - g * t;
            break;
        }

        if (v0 <= 0.0) {
            t_fall = 0.0;
            h_fall = 0.0;
            v_fall = 0.0;
            break;
        }
    }

    std::cout << "\n--- Rezul'tat (Moment padeniya) ---\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Moment padeniya (vremya t): " << t_fall << " sek.\n";
    std::cout << "Vysota v moment padeniya: " << h_fall << " m.\n";
    std::cout << "Skorost' v moment padeniya: " << v_fall << " m/s.\n";

    std::cout << "\nNazhmi Enter dlya vihoda...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}