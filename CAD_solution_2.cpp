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
    // Variables to hold user input
    double length, width, height;

    // User input for Rectangle dimensions
    std::cout << "Enter the length and width of the Rectangle: ";
    std::cin >> length >> width;

    // Create a Rectangle object using user input
    Rectangle rect(length, width);
    std::cout << "Area of Rectangle: " << calculateArea(rect) << std::endl;

    // User input for Cuboid dimensions
    std::cout << "Enter the length, width, and height of the Cuboid: ";
    std::cin >> length >> width >> height;

    // Create a Cuboid object using user input
    Cuboid cub(length, width, height);
    std::cout << "Volume of Cuboid: " << calculateVolume(cub) << std::endl;

    // Using the virtual function to calculate volume
    Shape* shape = &cub;
    std::cout << "Volume of Cuboid (using virtual function): " << shape->volume() << std::endl;

    return 0;
}
// In this solution the input is taken by the user
