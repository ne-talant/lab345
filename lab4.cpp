#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class Figure {
protected:
    double x, y;
public:
    Figure() {
        x = rand() % 500;
        y = rand() % 500;
    }
    Figure(double x0, double y0) {
        x = x0;
        y = y0;
    }
    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

class Line : public Figure {
protected:
    double x2, y2;
    double length;
public:
    Line() : Figure() {
        x2 = rand() % 500;
        y2 = rand() % 500;
        calculateLength();
    }
    Line(double x1, double y1, double x22, double y22) : Figure(x1, y1) {
        x2 = x22;
        y2 = y22;
        calculateLength();
    }
    void calculateLength() {
        length = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
    }
    void printLength() {
        cout << "Line length: " << length << endl;
    }
};

class Rectangle : public Figure {
protected:
    double width, height;
public:
    Rectangle() : Figure() {
        width = rand() % 100 + 1;
        height = rand() % 100 + 1;
    }
    Rectangle(double x0, double y0, double w, double h) : Figure(x0, y0) {
        width = w;
        height = h;
    }
    double perimeter() {
        return 2 * (width + height);
    }
    double area() {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    Square() : Rectangle() {
        height = width;
    }
    Square(double x0, double y0, double s) : Rectangle(x0, y0, s, s) {}
};

int main() {
    srand(time(0));

    Line l1;
    Line l2(0, 0, 3, 4);
    l1.printLength();
    l2.printLength();

    Square s1;
    Square s2(0, 0, 5);
    cout << s2.perimeter() << endl;
    cout << s2.area() << endl;

    Rectangle* arr = new Rectangle[3]{
        Rectangle(0,0,3,4),
        Rectangle(1,1,5,6),
        Rectangle(2,2,7,8)
    };

    for (int i = 0; i < 3; i++) {
        cout << arr[i].perimeter() << " " << arr[i].area() << endl;
    }

    delete[] arr;

    return 0;
}