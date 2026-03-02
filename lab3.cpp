#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class tPoint {
private:
    double x;
    double y;
    double dx;
    double dy;
public:
    tPoint() {
        x = rand() % 800;
        y = rand() % 600;
        dx = (rand() % 11 - 5) / 2.0;
        dy = (rand() % 11 - 5) / 2.0;
    }

    tPoint(double x0, double y0) {
        x = x0;
        y = y0;
        dx = (rand() % 11 - 5) / 2.0;
        dy = (rand() % 11 - 5) / 2.0;
    }

    void moveLinear() {
        x += dx;
        y += dy;
        if (x <= 0 || x >= 800) dx = -dx;
        if (y <= 0 || y >= 600) dy = -dy;
    }

    void moveRandom() {
        dx = (rand() % 11 - 5) / 2.0;
        dy = (rand() % 11 - 5) / 2.0;
        x += dx;
        y += dy;
        if (x <= 0) x = 0;
        if (x >= 800) x = 800;
        if (y <= 0) y = 0;
        if (y >= 600) y = 600;
    }

    void print() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    srand(time(0));
    tPoint points[100];
    for (int i = 0; i < 100; i++) {
        points[i].print();
        points[i].moveLinear();
    }
    return 0;
}