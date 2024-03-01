/*This GitHub code has been crafted by TIRTH JIGNESHKUMAR DALAL from CHARUSAT UNIVERSITY with a focus on simplifying and streamlining processes. 
It offers a user-friendly approach to solving problems, ensuring accessibility and ease of use for all stakeholders. 
The code demonstrates a commitment to clarity and efficiency, providing intuitive solutions to complex challenges. 
With clear documentation and concise implementation, this code fosters collaboration and empowers users to navigate and contribute effectively. 
It reflects a dedication to enhancing the developer experience and fostering a welcoming environment for innovation and growth.*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class CarManagementSystem {
private:
    struct Car {
        int number;
        string model;
        string fuelType;
        float showroomPrice;
        float mileage;
        string transmission;
        float tankCapacity;
        int seating;
        string airbags;
    };

    vector<Car> cars;

public:
    void feedCarDetails() {
        Car car;
        cout << "********************************************************************** ";
        cout << "\n*********************** WELCOME TO TATA MOTORS *********************** ";
        cout << "\n********************************************************************** ";
        cout << "\n\nEnter number of cars: ";
        cin >> car.number;

        for (int i = 0; i < car.number; ++i) {
            cout << "\nEnter details for Car #" << i + 1 << ":\n";
            cout << "Model name: ";
            cin.ignore();
            getline(cin, car.model);

            cout << "Fuel type (petrol/diesel/cng/electric): ";
            cin >> car.fuelType;

            cout << "Showroom price (in lakhs): ";
            cin >> car.showroomPrice;

            cout << "Mileage (in kmpl): ";
            cin >> car.mileage;

            cout << "Transmission (Manual/AMT): ";
            cin >> car.transmission;

            cout << "Tank capacity (in LITRES): ";
            cin >> car.tankCapacity;

            cout << "Seating capacity: ";
            cin >> car.seating;

            cout << "Airbags (Yes/No): ";
            cin >> car.airbags;

            cars.push_back(car);
        }
    }

    void retrieveCarData(int option, string value) {
        switch (option) {
            case 1: // Model name
                for (const auto& car : cars) {
                    if (car.model == value) {
                        printCarDetails(car);
                    }
                }
                break;

            case 2: // Fuel type
                for (const auto& car : cars) {
                    if (car.fuelType == value) {
                        printCarDetails(car);
                    }
                }
                break;

            case 3: // Price range
                float minPrice, maxPrice;
                cout << "Enter minimum price: ";
                cin >> minPrice;
                cout << "Enter maximum price: ";
                cin >> maxPrice;

                for (const auto& car : cars) {
                    if (car.showroomPrice >= minPrice && car.showroomPrice <= maxPrice) {
                        printCarDetails(car);
                    }
                }
                break;

            default:
                cout << "Invalid option!\n";
        }
    }

private:
    void printCarDetails(const Car& car) {
        cout << "\nCar details:\n";
        cout << "Model name: " << car.model << "\nFuel type: " << car.fuelType
             << "\nShowroom price: " << car.showroomPrice << "\nMileage: " << car.mileage
             << "\nTransmission: " << car.transmission << "\nTank capacity: " << car.tankCapacity
             << "\nSeating capacity: " << car.seating << "\nAirbags: " << car.airbags << "\n";
    }
};

int main() {
    CarManagementSystem cms;
    cms.feedCarDetails();

    int option;
    cout << "\n\nList of Cars";
    cout << "\n  (1) TIAGO     (2) PUNCH     (3)ALTROZ   (4) TIGOR   (5) NEXON ";
    cout << "\n  (6) HARRIER   (7) SAFARI  ";
    cout << "\n\n\nChoose an option for retrieval:\n";
    cout << "1. Model name\n2. Fuel type\n3. Price range\n";
    cin >> option;

    string value;
    switch (option) {
        case 1:
            cout << "Enter Model name: ";
            cin.ignore();
            getline(cin, value);
            break;

        case 2:
            cout << "Enter Fuel type: ";
            cin >> value;
            break;

        case 3:
            // Price range doesn't need a specific value at this point
            break;

        default:
            cout << "Invalid option!\n";
            return 1;
    }

    cms.retrieveCarData(option, value);

    cout << "\n23DCS018 Tirth J Dalal";

    return 0;
}
