/*This GitHub code has been crafted by TIRTH JIGNESHKUMAR DALAL from CHARUSAT UNIVERSITY with a focus on simplifying and streamlining processes. 
It offers a user-friendly approach to solving problems, ensuring accessibility and ease of use for all stakeholders. 
The code demonstrates a commitment to clarity and efficiency, providing intuitive solutions to complex challenges. 
With clear documentation and concise implementation, this code fosters collaboration and empowers users to navigate and contribute effectively. 
It reflects a dedication to enhancing the developer experience and fostering a welcoming environment for innovation and growth.*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

// Function to calculate the area of a circle
double calculateArea(double radius) {
    return PI * radius * radius;
}

// Function to calculate the area of a rectangle
double calculateArea(double length, double width) {
    return length * width;
}

// Function to calculate the surface area of a cuboid
double calculateArea(double height, double width, double depth) {
    return 2 * (depth * width + depth * height + width * height);
}

int main() {
    double radius, depth, length, width, height;

      cout << "********************************************************************** ";
    cout << "\n*********************** Overloading Function ************************* ";
    cout << "\n********************************************************************** ";


    cout << "\n\nEnter the radius of the circle: ";
    cin >> radius;
    cout << "Area of the circle: " << calculateArea(radius) << endl;

    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of the rectangle: " << calculateArea(length, width) << endl;

    cout << "Enter the height, width & depth; of the cuboid: ";
    cin >> height >> width >> depth;
    cout << "Surface area of the cuboid: " << calculateArea(height, width, depth) << endl;

    cout<< "\n23DCS018 Tirth J Dalal";

    return 0;
}

