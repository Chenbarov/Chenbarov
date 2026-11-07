#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    double v0 = 50.0, g = 9.8, dt = 0.1;
    std::vector<double> times, velocities;

    for (double t = 0.0; t <= v0 / g; t += dt) {
        times.push_back(t);
        velocities.push_back(v0 - g * t);
    }

    std::cout << std::setw(10) << "Vremya" << std::setw(10) << "Skorost" << "\n";
    for (size_t i = 0; i < times.size(); ++i)
        std::cout << std::setw(10) << times[i] << std::setw(10) << velocities[i] << "\n";
    return 0;
}
