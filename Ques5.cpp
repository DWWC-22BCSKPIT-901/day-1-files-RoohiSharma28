#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    Employee(const string& empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {}

    virtual ~Employee() {}

    virtual void calculateEarnings() = 0;

    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Base Salary: " << salary << endl;
    }
};

class Manager : public Employee {
    int performanceRating;

public:
    Manager(const string& empName, int empId, double empSalary, int rating)
        : Employee(empName, empId, empSalary), performanceRating(rating) {}

    void calculateEarnings() override {
        double bonus = 0.0;
        if (performanceRating >= 1 && performanceRating <= 5) {
            bonus = salary * (performanceRating * 0.1); // Bonus is 10% of salary per rating point
        }
        salary += bonus;
        cout << "Bonus Based on Performance Rating: " << bonus << endl;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Performance Rating: " << performanceRating << endl;
        cout << "Total Earnings: " << salary << endl;
    }
};

class Developer : public Employee {
    int extraHours;
    double hourlyRate;

public:
    Developer(const string& empName, int empId, double empSalary, int hours, double rate = 50.0)
        : Employee(empName, empId, empSalary), extraHours(hours), hourlyRate(rate) {}

    void calculateEarnings() override {
        double overtime = extraHours * hourlyRate;
        salary += overtime;
        cout << "Overtime Compensation: " << overtime << endl;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Extra Hours Worked: " << extraHours << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Total Earnings: " << salary << endl;
    }
};

int main() {
    int employeeType;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> employeeType;

    string name;
    int id;
    double salary;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Base Salary: ";
    cin >> salary;

    if (employeeType == 1) {
        int rating;
        cout << "Enter Performance Rating (1-5): ";
        cin >> rating;

        unique_ptr<Employee> employee = make_unique<Manager>(name, id, salary, rating);
        employee->calculateEarnings();
        employee->displayDetails();

    } else if (employeeType == 2) {
        int extraHours;
        cout << "Enter Extra Hours Worked: ";
        cin >> extraHours;

        unique_ptr<Employee> employee = make_unique<Developer>(name, id, salary, extraHours);
        employee->calculateEarnings();
        employee->displayDetails();

    } else {
        cout << "Invalid Employee Type!" << endl;
    }

    return 0;
}
