#include <iostream>
#include <stack>
using namespace std;

// Point class
class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    int operator==(const Point& other) const {
        return (x == other.x && y == other.y) ? 1 : 0;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Manual stack class (non-STL)
class PointStack {
private:
    static const int MAX = 100;
    Point data[MAX];
    int top;

public:
    PointStack() : top(-1) {}

    void push(Point p) {
        if (top < MAX - 1)
            data[++top] = p;
        else
            cout << "Manual stack is full." << endl;
    }

    Point pop() {
        if (top >= 0)
            return data[top--];
        cout << "Manual stack is empty." << endl;
        return Point();
    }

    int isEmpty() const {
        return (top == -1) ? 1 : 0;
    }
};

int main() {
    double x_input, y_input;
    Point p1, p2, result;

    cout << "Enter x and y for Point 1: ";
    cin >> x_input >> y_input;
    p1 = Point(x_input, y_input);

    cout << "Enter x and y for Point 2: ";
    cin >> x_input >> y_input;
    p2 = Point(x_input, y_input);

    // Create both stacks
    stack<Point> stlStack;
    PointStack manualStack;

    // Perform addition
    result = p1 + p2;
    cout << endl << "Addition (p1 + p2): ";
    result.display();
    stlStack.push(result);
    manualStack.push(result);

    // Negate p1
    result = -p1;
    cout << "Negation of p1: ";
    result.display();
    stlStack.push(result);
    manualStack.push(result);

    // Negate p2
    result = -p2;
    cout << "Negation of p2: ";
    result.display();
    stlStack.push(result);
    manualStack.push(result);

    // Equality check
    cout << "p1 and p2 are ";
    cout << ((p1 == p2) ? "Equal" : "Not Equal") << endl;

    // Undo with STL
    cout << endl << "Undoing with STL stack:" << endl;
    while (!stlStack.empty()) {
        Point last = stlStack.top();
        last.display();
        stlStack.pop();
    }

    // Undo with manual stack (FIXED)
    cout << endl << "Undoing with manual stack:" << endl;
    while (manualStack.isEmpty() == 0) {
        Point last = manualStack.pop();
        last.display();
    }

    cout << "24CE108_VIVEK_SANGANI" << endl;
    return 0;
}
