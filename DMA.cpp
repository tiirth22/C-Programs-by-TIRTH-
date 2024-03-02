/*This GitHub code has been crafted by TIRTH JIGNESHKUMAR DALAL from CHARUSAT UNIVERSITY with a focus on simplifying and streamlining processes. 
It offers a user-friendly approach to solving problems, ensuring accessibility and ease of use for all stakeholders. 
The code demonstrates a commitment to clarity and efficiency, providing intuitive solutions to complex challenges. 
With clear documentation and concise implementation, this code fosters collaboration and empowers users to navigate and contribute effectively. 
It reflects a dedication to enhancing the developer experience and fostering a welcoming environment for innovation and growth.*/

#include <iostream>
#include <cmath>

class Circle {
private:
    static int totalObjects;
    static int activeObjects;
    double radius;
    
public:
    Circle() : radius(1.0) {
        totalObjects++;
        activeObjects++;
    }

    Circle(double r) : radius(r) {
        totalObjects++;
        activeObjects++;
    }

    Circle(const Circle& other) : radius(other.radius) {
        totalObjects++;
        activeObjects++;
    }

    ~Circle() {
        activeObjects--;
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
};

int Circle::totalObjects = 0;
int Circle::activeObjects = 0;

int main() {
    Circle* circle1 = new Circle(); // Creating circle object with default radius
    Circle* circle2 = new Circle(20.0); // Creating circle object with radius 3
    Circle* circle3 = new Circle(*circle2); // Creating circle object by copying circle2

    std::cout << "Area of circle1: " << circle1->area() << std::endl;
    std::cout << "Area of circle2: " << circle2->area() << std::endl;
    std::cout << "Area of circle3: " << circle3->area() << std::endl;

    std::cout << "Total circle objects created: " << Circle::getTotalObjects() << std::endl;
    std::cout << "Active circle objects: " << Circle::getActiveObjects() << std::endl;

    delete circle1;
    std::cout << "Active circle objects after deleting circle1: " << Circle::getActiveObjects() << std::endl;

    delete circle2;
    std::cout << "Active circle objects after deleting circle2: " << Circle::getActiveObjects() << std::endl;

    delete circle3;
    std::cout << "Active circle objects after deleting circle3: " << Circle::getActiveObjects() << std::endl;

    return 0;
}
