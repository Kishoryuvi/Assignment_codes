#include <iostream>

// Forward declaration
class Rectangle;

// Friend function to calculate the area of a Rectangle
double calculateArea(const Rectangle& rect);

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // Friend function declaration
    friend double calculateArea(const Rectangle& rect);
};

// Definition of the friend function to calculate the area of a Rectangle
double calculateArea(const Rectangle& rect) {
    return rect.length * rect.width;
}
// Base class for 3D shapes
class Shape {
public:
    virtual double volume() const = 0; // Pure virtual function
};

// Forward declaration
class Cuboid;

// Friend function to calculate the volume of a Cuboid
double calculateVolume(const Cuboid& cuboid);

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    // Constructor
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}

    // Override the volume function from Shape
    double volume() const override {
        return length * width * height;
    }

    // Friend function declaration
    friend double calculateVolume(const Cuboid& cuboid);
};

// Definition of the friend function to calculate the volume of a Cuboid
double calculateVolume(const Cuboid& cuboid) {
    return cuboid.length * cuboid.width * cuboid.height;
}

int main() {
    // Creating a Rectangle object
    Rectangle rect(5.0, 3.0);
    std::cout << "Area of Rectangle: " << calculateArea(rect) << std::endl;

    // Creating a Cuboid object
    Cuboid cub(5.0, 3.0, 4.0);
    std::cout << "Volume of Cuboid: " << calculateVolume(cub) << std::endl;

    // Using the virtual function to calculate volume
    Shape* shape = &cub;
    std::cout << "Volume of Cuboid (using virtual function): " << shape->volume() << std::endl;

    return 0;
}

// In this code I have created the lengths and width by myself 
