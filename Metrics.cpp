#include <iostream>
#include <cmath>

class Circle {
private:
    static int totalObjects;
    static int activeObjects;
    static int deletedObjects; // Corrected variable name
    double radius;

public:
    Circle() : radius(1.0) {
        totalObjects++;
        activeObjects++;
    }

    explicit Circle(double r) : radius(r) {
        totalObjects++;
        activeObjects++;
    }

    Circle(const Circle& other) : radius(other.radius) {
        totalObjects++;
        activeObjects++;
    }

    ~Circle() {
        activeObjects--;
        deletedObjects++;
    }

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    double area() const {
        return M_PI * radius * radius;
    }

    static int getTotalObjects() {
        return totalObjects;
    }

    static int getActiveObjects() {
        return activeObjects;
    }

    static int getDeletedObjects() {
        return deletedObjects;
    }
};

int Circle::totalObjects = 0;
int Circle::activeObjects = 0;
int Circle::deletedObjects = 0;

int main() {
    Circle* circle1 = new Circle();
    Circle* circle2 = new Circle(20.0);
    Circle* circle3 = new Circle(*circle2);

    std::cout << "Area of circle1: " << circle1->area() << std::endl;
    std::cout << "Area of circle2: " << circle2->area() << std::endl;
    std::cout << "Area of circle3: " << circle3->area() << std::endl;

    std::cout << "Total circle objects created: " << Circle::getTotalObjects() << std::endl;
    std::cout << "Active circle objects: " << Circle::getActiveObjects() << std::endl;

    delete circle1;
    delete circle2;
    delete circle3;

    std::cout << "Deleted circle objects: " << Circle::getDeletedObjects() << std::endl;

    std::cout << "Total circle objects created: " << Circle::getTotalObjects() << std::endl;
    std::cout << "Active circle objects: " << Circle::getActiveObjects() << std::endl;

    return 0;
}
