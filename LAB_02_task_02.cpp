// Syed Haris Hussain Shah
// L1F23BSCS0697
#include <iostream>
using namespace std;

// Abstract class Employee
class Employee {
protected:
    string name;
public:
    Employee(string n) : name(n) {}
    virtual double calculateSalary() = 0; 
    virtual void display() {
        cout << "Employee Name: " << name << endl;
    }
 
};

// FullTimeEmployee class
class FullTimeEmployee : public Employee {
private:
    double fixedSalary;
public:
    FullTimeEmployee(string n, double salary) : Employee(n), fixedSalary(salary) {}

    double calculateSalary() override {
        return fixedSalary;
    }

    void display() override {
        Employee::display();
        cout << "Full-Time Employee Salary: $" << fixedSalary << endl;
    }
};

// PartTimeEmployee class
class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;
public:
    PartTimeEmployee(string n, int hours, double rate) : Employee(n), hoursWorked(hours), hourlyRate(rate) {}

    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    void display() override {
        Employee::display();
        cout << "Part-Time Employee Salary: $" << calculateSalary() << endl;
    }
};

// Main function
int main() {
    Employee* fullTimeEmployee = new FullTimeEmployee ("Ahmad", 10000);
    Employee* partTimeEmployee = new PartTimeEmployee ("Ali", 43, 3000);

    fullTimeEmployee->display();
    cout << endl;
    partTimeEmployee->display();


    delete fullTimeEmployee;
    delete partTimeEmployee;

    return 0;
}
