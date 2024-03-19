/*This GitHub code has been crafted by TIRTH JIGNESHKUMAR DALAL from CHARUSAT UNIVERSITY with a focus on simplifying and streamlining processes. 
It offers a user-friendly approach to solving problems, ensuring accessibility and ease of use for all stakeholders. 
The code demonstrates a commitment to clarity and efficiency, providing intuitive solutions to complex challenges. 
With clear documentation and concise implementation, this code fosters collaboration and empowers users to navigate and contribute effectively. 
It reflects a dedication to enhancing the developer experience and fostering a welcoming environment for innovation and growth.*/


#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 1000;

class EmployeeManagementSystem {
private:
    struct Employee {
        int employeeID;
        string employeeName;
        float qualification;
        float experience;
        long long contactNumber;
    };

    Employee employees[MAX_EMPLOYEES];
    int numEmployees;

public:
    EmployeeManagementSystem() : numEmployees(0) {}

    void storeEmployeeDetails() {
        if (numEmployees >= MAX_EMPLOYEES) {
            cout << "Cannot add more employees. Maximum limit reached." << endl;
            return;
        }

        cout << "Enter Employee ID (4-digit number): ";
        cin >> employees[numEmployees].employeeID;

        cout << "Enter Employee Name (string with space): ";
        cin.ignore();
        getline(cin, employees[numEmployees].employeeName);

        cout << "Enter Qualification (floating point number): ";
        cin >> employees[numEmployees].qualification;

        cout << "Enter Experience (floating point number): ";
        cin >> employees[numEmployees].experience;

        cout << "Enter Contact Number (10-digit number): ";
        cin >> employees[numEmployees].contactNumber;

        numEmployees++;
        cout << "Employee details stored successfully." << endl;
    }

    void retrieveEmployeeDetails(int employeeID) {
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

    float calculateAverageExperience() {
        if (numEmployees == 0)
            return 0;
        float totalExperience = 0;
        for (int i = 0; i < numEmployees; i++) {
            totalExperience += employees[i].experience;
        }
        return totalExperience / numEmployees;
    }

    void startSystem() {
        int choice;
        do {
            cout << "\n------------------- Employee Management System -------------------\n";
            cout << "1. Store Employee Details\n";
            cout << "2. Retrieve Employee Details\n";
            cout << "3. Calculate Average Experience of Employees\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    storeEmployeeDetails();
                    break;
                case 2:
                    if (numEmployees == 0) {
                        cout << "No employee details available. Please store employee details first." << endl;
                    } else {
                        int empID;
                        cout << "Enter Employee ID to retrieve details: ";
                        cin >> empID;
                        retrieveEmployeeDetails(empID);
                    }
                    break;
                case 3:
                    if (numEmployees == 0) {
                        cout << "No employee details available. Please store employee details first." << endl;
                    } else {
                        float averageExperience = calculateAverageExperience();
                        cout << "Average Experience of Employees: " << averageExperience << endl;
                    }
                    break;
                case 4:
                    cout << "Exiting the program. Thank you!\n";
                    break;
                default:
                    cout << "Invalid choice Please enter a valid option.\n";
        }

    } while (choice != 4);

  }
};

int main() {
    EmployeeManagementSystem ems;
    ems.startSystem();
    return 0;
}
