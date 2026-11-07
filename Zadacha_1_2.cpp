#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

void genTrajectory(double v0, double g, double dt, std::vector<double>& times, std::vector<double>& heights) {

	if (v0 <= 0) return;

	size_t est_size = static_cast<size_t>(v0 * 2 / g / dt);
	times.reserve(est_size);
	heights.reserve(est_size);

	for (double t = 0; ; t += dt) {
		double h = v0 * t - 0.5 * g * t * t;
		if (h < 0) break;
		times.push_back(t);
		heights.push_back(h);
	}
}

int main() {
	std::cout << std::fixed << std::setprecision(2);

	double v0 = 0.0;
	std::cout << "Vvedite nachalnuyu skorost rakety (v0, m/c): ";
	if (!(std::cin >> v0) || v0 <= 0) {
		std::cout << "Oshibka: Otriczatelnaya nachalnaya skorost!";
		return 1;
	}
	double g = 9.8, dt = 0.001;
	std::vector<double> times, heights;

	genTrajectory(v0, g, dt, times, heights);

	if (heights.empty()) {
		std::cout << "Oshibka: Pustoy vektor vysoty!";
		return 0;
	}

	auto max_it = std::max_element(heights.begin(), heights.end());
	size_t idx_max = std::distance(heights.begin(), max_it);

	std::cout << "\n Resultaty zadachy:\n"
		"Maksimalnaya vysota: " << *max_it << " m\n"
		"Vremya dostijeniya: " << times[idx_max] << " c\n"
		"Indeks elementa: " << idx_max << "\n";

	return 0;
}