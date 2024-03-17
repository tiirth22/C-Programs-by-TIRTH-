/*This GitHub code has been crafted by TIRTH JIGNESHKUMAR DALAL from CHARUSAT UNIVERSITY with a focus on simplifying and streamlining processes. 
It offers a user-friendly approach to solving problems, ensuring accessibility and ease of use for all stakeholders. 
The code demonstrates a commitment to clarity and efficiency, providing intuitive solutions to complex challenges. 
With clear documentation and concise implementation, this code fosters collaboration and empowers users to navigate and contribute effectively. 
It reflects a dedication to enhancing the developer experience and fostering a welcoming environment for innovation and growth.*/

#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imaginary;

public:
    Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}

    Complex& operator+=(const Complex &other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }

    Complex& operator-=(const Complex &other) {
        real -= other.real;
        imaginary -= other.imaginary;
        return *this;
    }

    Complex& operator*=(const Complex &other) {
        float newReal = real * other.real - imaginary * other.imaginary;
        float newImaginary = real * other.imaginary + imaginary * other.real;
        real = newReal;
        imaginary = newImaginary;
        return *this;
    }

    Complex& operator/=(const Complex &other) {
        float divisor = other.real * other.real + other.imaginary * other.imaginary;
        float newReal = (real * other.real + imaginary * other.imaginary) / divisor;
        float newImaginary = (imaginary * other.real - real * other.imaginary) / divisor;
        real = newReal;
        imaginary = newImaginary;
        return *this;
    }

    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
};

int main() {
    float real1, imaginary1, real2, imaginary2;
    char operation;

    cout << "Enter the real part of the first complex number: ";
    cin >> real1;
    cout << "Enter the imaginary part of the first complex number: ";
    cin >> imaginary1;

     cout << "Enter the real part of the second complex number: ";
    cin >> real2;
    cout << "Enter the imaginary part of the second complex number: ";
    cin >> imaginary2;

    Complex num1(real1, imaginary1);
    Complex num2(real2, imaginary2);

    cout << "Enter operation (1, 2, 3, 4): ";
    cout << "\n(+) ADDITION";
    cout << "\n(-) SUBTRACTION";
    cout << "\n(+) MULTIPLICATION";
    cout << "\n(+) DIVISION";

    cin >> operation;

    Complex result;

    switch(operation) {
        case '1':
            result = num1;
            result += num2;
            cout << "Sum: " << result << endl;
            break;
        case '2':
            result = num1;
            result -= num2;
            cout << "Difference: " << result << endl;
            break;
        case '3':
            result = num1;
            result *= num2;
            cout << "Product: " << result << endl;
            break;
        case '4':
            result = num1;
            result /= num2;
            cout << "Quotient: " << result << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }

    return 0;
}
