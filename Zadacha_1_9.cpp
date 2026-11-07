#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main() {
    std::setlocale(LC_ALL, "Russian");
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    double v0 = 0.0;
    double g = 9.8;
    double dt = 0.2;

    std::cout << "Vvedite nachalnuyu skorost' rakety (v0, m/s): ";
    if (!(std::cin >> v0)) return 1;

    std::vector<double> h;

    for (double t = 0.0; ; t += dt) {
        double chistaya_vysota = v0 * t - 0.5 * g * t * t;
        if (chistaya_vysota < 0.0 && t > 0.1) {
            h.push_back(0.0);
            break;
        }

        double shum = (std::rand() % 600 - 300) / 100.0;
        double izmerennaya_vysota = chistaya_vysota + shum;
        if (izmerennaya_vysota < 0.0) izmerennaya_vysota = 0.0;

        h.push_back(izmerennaya_vysota);
    }

    size_t n = h.size();
    std::vector<double> smoothed(n);

    if (n > 0) {
        smoothed[0] = h[0];
        smoothed[n - 1] = h[n - 1];
    }

    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    std::cout << "\nS shumom | Sglazhenno\n";
    for (size_t i = 0; i < n; ++i) {
        std::cout << std::fixed << std::setprecision(2)
            << h[i] << " | " << smoothed[i] << "\n";
    }

    std::cout << "\nNazhmi Enter dlya vihoda...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}
