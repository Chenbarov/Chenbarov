#include <iostream>
#include <vector>
#include <iomanip>

struct Point {
    double x, y, z;
};

class Rocket {
private:
    Point pos;
    double vx, vy, vz;
    double g;

public:
    Rocket(double x, double y, double z, double vx, double vy, double vz)
        : pos{ x, y, z }, vx(vx), vy(vy), vz(vz), g(9.8) {
    }

    void updatePosition(double dt) {
        pos.x += vx * dt;
        pos.y += vy * dt - 0.5 * g * dt * dt;
        pos.z += vz * dt;

        vy -= g * dt;
        if (pos.y < 0.0) {
            pos.y = 0.0;
            vy = 0.0;
            vx = 0.0;
            vz = 0.0;
        }
    }

    Point getPosition() const {
        return pos;
    }
};

int main() {
    std::setlocale(LC_ALL, "Russian");

    std::vector<Rocket> squad;
    squad.reserve(5);

    squad.emplace_back(0, 0, 0, 10, 50, 5);
    squad.emplace_back(0, 0, 0, 15, 40, 10);
    squad.emplace_back(0, 0, 0, 20, 60, -5);
    squad.emplace_back(0, 0, 0, 5, 30, 0);
    squad.emplace_back(0, 0, 0, 25, 45, 15);

    double T = 10.0;
    double dt = 0.1;

    std::vector<std::vector<Point>> trajectories(squad.size());

    for (double t = 0.0; t <= T; t += dt) {
        for (size_t i = 0; i < squad.size(); ++i) {
            trajectories[i].push_back(squad[i].getPosition());
            squad[i].updatePosition(dt);
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Konechnoe polozhenie raket posle " << T << " sek:\n";
    for (size_t i = 0; i < squad.size(); ++i) {
        Point p = squad[i].getPosition();
        std::cout << "Raketa " << i + 1 << ": X = " << p.x << ", Y = " << p.y << ", Z = " << p.z << "\n";
    }

    std::cout << "\nNazhmi Enter dlya vihoda...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}
