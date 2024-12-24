#include <iostream>
#include <cmath> 
using namespace std;

double calculateArea(double radius) {
    return M_PI * radius * radius; 
}

double calculateArea(double length, double width) {
    return length * width; 
}

double calculateArea(double base, double height, bool isTriangle) {
    if (isTriangle) {
        return 0.5 * base * height; 
    }
    return 0.0; 
}

int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    double length, width;
    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;

    double base, height;
    cout << "Enter the base and height of the triangle: ";
    cin >> base >> height;

    double circleArea = calculateArea(radius);
    double rectangleArea = calculateArea(length, width);
    double triangleArea = calculateArea(base, height, true);

    cout << "\nAreas of the shapes:" << endl;
    cout << "Circle: " << circleArea << endl;
    cout << "Rectangle: " << rectangleArea << endl;
    cout << "Triangle: " << triangleArea << endl;

    return 0;
}
