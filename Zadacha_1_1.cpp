#include <iostream>
#include <vector>
#include <iomanip>

int main() {
	double v0 = 50.0, g = 9.8, dt = 1.0;
	if (v0 <= 0) {
		std::cout << "Preduprejdenie : v0 <= 0!\n";
		return 0;
	}
	std::vector<double> times, heights;
	times.reserve(static_cast<size_t>(v0 * 2 / g / dt));
	heights.reserve(times.capacity());

	for (double t = 0; ; t += dt) {
		double h = v0 * t - 0.5 * g * t * t;
		if (h < 0) break;
		times.push_back(t);
		heights.push_back(h);
	}
	
	std::cout << std::fixed << std::setprecision(2) << "Vremya\tVysota\n";
	for (size_t i = 0; i < times.size(); i++)
		std::cout << std::setw(5) << times[i] << "\t" << std::setw(7) << heights[i] << "\n";
	return 0;
}
