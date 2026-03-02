#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
    virtual double perimeter() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
protected:
    double width, height;
    static int created;
    static int existing;
public:
    Rectangle() {
        width = 1;
        height = 1;
        created++;
        existing++;
    }
    Rectangle(double w, double h) {
        width = w;
        height = h;
        created++;
        existing++;
    }
    Rectangle(const Rectangle& r) {
        width = r.width;
        height = r.height;
        created++;
        existing++;
    }
    ~Rectangle() {
        existing--;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    static void printCount() {
        cout << "Created: " << created << " Existing: " << existing << endl;
    }
};

int Rectangle::created = 0;
int Rectangle::existing = 0;

class Square : public Rectangle {
public:
    Square(double s) : Rectangle(s, s) {}
};

class Circle : public Figure {
    double r;
public:
    Circle(double r0) { r = r0; }
    double perimeter() const override {
        return 2 * 3.14159 * r;
    }
};

class Ellipse : public Figure {
    double a, b;
public:
    Ellipse(double a0, double b0) { a = a0; b = b0; }
    double perimeter() const override {
        return 3.14159 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    }
};

int main() {
    Rectangle r1;
    Rectangle r2(3, 4);
    Rectangle::printCount();

    Rectangle* pr = new Rectangle(5, 6);
    Rectangle::printCount();

    Figure* arr[4];
    arr[0] = new Square(5);
    arr[1] = new Rectangle(2, 3);
    arr[2] = new Circle(3);
    arr[3] = new Ellipse(4, 2);

    Rectangle::printCount();

    for (int i = 0; i < 4; i++)
        cout << arr[i]->perimeter() << endl;

    for (int i = 0; i < 4; i++)
        delete arr[i];

    delete pr;

    Rectangle::printCount();

    return 0;
}