#include <iostream>
#include <vector>
#include <numeric> 
#include <iomanip> 

int main() {
    double v0 = 50.0, g = 9.8, dt = 0.1;
    std::vector<double> times, velocities;

    //Задача 3(дубликат)
    for (double t = 0.0; ; t += dt) {
        double v = v0 - g * t;
        if (v < 0.0) break; 

        times.push_back(t);
        velocities.push_back(v);
    }

    std::cout << "tablitza skorostey\n";
    std::cout << std::setw(10) << "Vremya" << std::setw(10) << "Skorost" << "\n";
    for (size_t i = 0; i < times.size(); ++i) {
        std::cout << std::setw(10) << times[i] << std::setw(10) << velocities[i] << "\n";
    }

    //задача 4
    if (velocities.empty()) {
        std::cout << "\nOshibka!\n";
            return 0;
    }

    double sum = std::accumulate(velocities.begin(), velocities.end(), 0.0);
        double avg = sum / velocities.size(); 

    std::cout << "\nResultaty: \n";
    std::cout << "Summa skorostey: " << sum << "\n";
    std::cout << "Srednyaya skorost: " << std::fixed << std::setprecision(2) << avg << " m/c\n";

        return 0;
}
