#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
// Добавил шаг по dt = 0.01 и возможность выбирать усреднение.

int main() {
    double v0 = 0.0, g = 9.8, dt = 0.01;

    std::cout << "Vvedite nachalnuyu skorost (v0, m/c): ";
    if (!(std::cin >> v0)) return 1;

    std::cout << "Vyberite usredneniye:\n"
        << "0 - Net usredneniya\n"
        << "1 - Po 1 sekunde\n"
        << "10 - Po 10 sekund\n"
        << "100 - Po 100 sekund\n"
        << "Vash vybor (0, 1, 10, 100): ";
    int choice = 0;
    std::cin >> choice;

    std::vector<double> times, velocities;
    for (double t = 0.0; ; t += dt) {
        double v = v0 - g * t;
        if (v < 0.0) break;
        times.push_back(t);
        velocities.push_back(v);
    }

    if (velocities.empty()) {
        std::cout << "Oshibka!\n";
    }
    else {
        std::vector<double> out_times, out_velocities;

        if (choice == 0) {
            out_times = times;
            out_velocities = velocities;
        }
        else {
            double window = choice;
            double sum_v = 0.0, sum_t = 0.0;
            size_t count = 0;
            double current_window_start = times[0];

            for (size_t i = 0; i < times.size(); ++i) {
                sum_v += velocities[i];
                sum_t += times[i];
                count++;

                if (times[i] - current_window_start >= window || i + 1 == times.size()) {
                    out_times.push_back(sum_t / count);
                    out_velocities.push_back(sum_v / count);
                    sum_v = 0.0; sum_t = 0.0; count = 0;
                    current_window_start = times[i];
                }
            }
        }

        std::cout << "\n" << std::setw(10) << "Vremya" << std::setw(15) << "Skorost" << "\n";
        for (size_t i = 0; i < out_times.size(); ++i)
            std::cout << std::setw(10) << out_times[i] << std::setw(15) << out_velocities[i] << "\n";

        double total_sum = std::accumulate(velocities.begin(), velocities.end(), 0.0);
        std::cout << "\nSrednyaya skorost: " << std::fixed << std::setprecision(2)
            << total_sum / velocities.size() << " m/c\n";
    }

    std::cout << "\nNazhmy Enter dlya vykhoda...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}
