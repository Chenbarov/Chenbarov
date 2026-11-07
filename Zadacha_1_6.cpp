#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    double v0 = 0.0;
    double g = 9.8;
    double dt = 0.01;

    std::cout << "Vvedite nachalnuyu skorost' rakety (v0, m/s): ";
    if (!(std::cin >> v0)) return 1;

    std::vector<double> heights;

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0) {
            heights.push_back(0.0); 
            break;
        }
        heights.push_back(h);
    }

    std::cout << "\n--- Ishodnyy vektor vysot (vsego tochek: " << heights.size() << ") ---\n";
    for (size_t i = 0; i < std::min(heights.size(), (size_t)15); ++i) {
        std::cout << std::fixed << std::setprecision(2) << heights[i] << " ";
    }
    if (heights.size() > 15) std::cout << "... (i dr.)";
    std::cout << "\n";

    heights.erase(
        std::remove_if(heights.begin(), heights.end(), [](double h) {
            return h < 10.0; 
            }),
        heights.end()
    );

    std::cout << "\n--- Ochischennyy vektor (vysoty >= 10.0) ---\n";
    if (heights.empty()) {
        std::cout << "Vektor stal pustym (net znacheniy >= 10.0).\n";
    }
    else {
        for (double h : heights) {
            std::cout << std::fixed << std::setprecision(2) << "\n" << h << "\n" << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nNazhmi Enter dlya vihoda...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}