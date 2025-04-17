// L1F23BSCS0697
// SYED HARIS HUSSAIN SHAH 

#include <iostream>
using namespace std;

class Customer {
    string name;
    int customerId;
public:
    Customer() {
        name = "";
        customerId = -1;
    }
    Customer(string name,int id) {
        this->name = name;
        customerId = id;
    }
    string getName() const {
        return name;
    }
    void setName(string n) {
        name = n;
    }
    int getId() {
        return customerId;
    }
    void setId(int id) { this->customerId = id; }
};

class CircularQueue {
private:
    int front;
    int rear;
    int size;
    int count;
    Customer* arr;
public:
    CircularQueue(int s) {
        size = s;
        arr = new Customer[size];
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(Customer c) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more customers." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = c;
        count++;
        cout << "Customer added to the queue."<<endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No customer to remove."<<endl;
            return;
        }

        cout << "Customer removed: " << arr[front].getName() <<"Id: "<< arr[front].getId() << endl;
        if (front == rear) {
            // only one element
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        count--;
    }

    void displayCount() {
        cout << "Number of customers in line: " << count << endl;
    }

    void viewFront() {
        if (isEmpty()) {
            cout << "Queue is empty."<<endl;
        }
        else {
            cout << "First customer Name: " << arr[front].getName() << endl;
            cout << "First customer Id: " << arr[front].getId() << endl;
        }
    }

    void viewRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Last customer Name: " << arr[rear].getName() << endl;
            cout << "Last customer Id: " << arr[rear].getId() << endl;

        }
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue queue(10);  
    int choice;
    string name;

    do {
        cout << "Coffee Shop Queue Menu " << endl;
        cout << "1. Add a customer to the queue" << endl;
        cout << "2. Remove the first customer" << endl;
        cout << "3. Display number of customers waiting" << endl;
        cout << "4. View the first customer" << endl;
        cout << "5. View the last customer" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: {
            cout << "Enter customer's name: ";
            cin >> name;
            int id;
            cout << "Enter Customer Id: ";
            cin >> id;
            Customer s1(name, id);
            queue.enqueue(s1);
            break;
        }   
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.displayCount();
            break;
        case 4:
            queue.viewFront();
            break;
        case 5:
            queue.viewRear();
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
