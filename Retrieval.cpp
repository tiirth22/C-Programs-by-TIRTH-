#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int employeeID;
    string employeeName;
    string qualification;
    float experience;
    long long contactNumber;
};

const int MAX_EMPLOYEES = 1000;

void storeEmployeeDetails(Employee employees[], int &numEmployees) {
    if (numEmployees >= MAX_EMPLOYEES) {
        cout << "Cannot add more employees. Maximum limit reached." << endl;
        return;
    }

    cout << "Enter Employee ID (4-digit number): ";
    cin >> employees[numEmployees].employeeID;

    cout << "Enter Employee Name (string with space): ";
    cin.ignore();
    getline(cin, employees[numEmployees].employeeName);

    cout << "Enter Qualification : ";
    cin.ignore();
    getline(cin, employees[numEmployees].qualification);


    cout << "Enter Experience (floating point number): ";
    cin >> employees[numEmployees].experience;

    cout << "Enter Contact Number (10-digit number): ";
    cin >> employees[numEmployees].contactNumber;

    numEmployees++;
    cout << "Employee details stored successfully." << endl;
}

void retrieveEmployeeDetails(const Employee employees[], int numEmployees, int employeeID) {
    bool found = false;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == employeeID) {
            cout << "\n------------------- Employee Details -------------------\n";
            cout << "Employee ID: " << employees[i].employeeID << endl;
            cout << "Employee Name: " << employees[i].employeeName << endl;
            cout << "Qualification: " << employees[i].qualification << endl;
            cout << "Experience: " << employees[i].experience << endl;
            cout << "Contact Number: " << employees[i].contactNumber << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID " << employeeID << " not found." << endl;
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    int choice;
    do {
        cout << "\n------------------- Employee Management System -------------------\n";
        cout << "1. Store Employee Details\n";
        cout << "2. Retrieve Employee Details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                storeEmployeeDetails(employees, numEmployees);
                break;
            case 2:
                if (numEmployees == 0) {
                    cout << "No employee details available. Please store employee details first." << endl;
                } else {
                    int empID;
                    cout << "Enter Employee ID to retrieve details: ";
                    cin >> empID;
                    retrieveEmployeeDetails(employees, numEmployees, empID);
                }
                break;
            case 3:
                cout << "Exiting the program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    cout << "\n23DCS018 Tirth J Dalal";

    return 0;
}
