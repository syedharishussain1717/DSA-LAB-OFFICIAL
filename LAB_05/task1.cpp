// L1F23BSCS0697
// SYED HARIS HUSSAIN SHAH
#include <iostream>
using namespace std;
// student class 
class Student 
{
private:
    string name;
    int score;
    int timeTaken;
public:
    // defualt constructor 
    Student() {
        name = "";
        score = 0;
        timeTaken = 0;
    }
    // parameterized constructor 
    Student(string name) {
        this->name = name;
        this->score = 0;
        this->timeTaken = 0;
    }

    void display() {
        cout << "Name: " << name << ", Score: " << score << ", Time Taken: " << timeTaken << " mins" << endl;
    }

    string getName() const { return name; }
    void setName(string name) { this->name = name; }

    int getScore() { return score; }
    void setScore(int setScore) { this->score = setScore; }
  
    int getTimeTaken() const { return timeTaken; }
    void setTimeTaken(int time) { this->timeTaken = time; }
};

class Queue 
{
private:
    int size;
    Student *arr;
    int front;
    int rear;
public:
    // parameterized constructor
    Queue( int size ) {
        this->size = size;
        this->arr = new Student[size];
        front = - 1;
        rear = - 1;
    }
     // check whether the queue is empty or not
    bool isEmpty() {
        if (front == -1)
        {
            return true;
        }
        else {
            return false;
        }
        
    }

    // check whether the queue is full or not
    bool isFull() {
        if (rear == size - 1)
        {
            return true;
        }
        else {
            return false;
        }
  
    }
  
    void enqueue(Student s) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more students. " << endl;
            return;
        }
        if (isEmpty()) { front = 0; }
        // FIX: initialize front when adding first element
        rear++;
        arr[rear] = s;
    }

   
    Student dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. " << endl;
            return Student();
        }
        Student s = arr[front];
        front++;
        return s;
    }
    // display function to dispaly queue entities
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty. " << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            arr[i].display();
        }
    }
};

void generateScoreAndTime(Student& s)
{
    // Random score between 0-100
    s.setScore(rand() % 101) ;
    // Random time between 5-20 minutes
    s.setTimeTaken(5 + rand() % 16);
}


int main() 
{
    srand(time(0)); 
    Queue waitingQueue(20);
    Queue finishedQueue(20);

    int choice;
    do {
        cout << "Quiz Competition Menu " << endl;
        cout << "1. Add a student to the waiting queue" << endl;
        cout << "2. Start the quiz and generate scores" << endl;
        cout << "3. Display results" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // To consume newline left by cin

        if (choice == 1 ) {
            string name;
            cout << "Enter student name: ";
            cin >> name;
            Student s(name);
            waitingQueue.enqueue(s);
            cout << "Student added to the waiting queue." << endl;;
        }
        else if (choice == 2) {
            if (waitingQueue.isEmpty()) {
                cout << "No students in waiting queue." << endl;;
            }
            else {
                Student s = waitingQueue.dequeue();
                generateScoreAndTime(s);
                finishedQueue.enqueue(s);
                cout << "Quiz attempted by: " << s.getName() << endl;
            }
            if (waitingQueue.isEmpty())
                cout << "Quiz has ended. All students have attempted the quiz." << endl;
        }
        else if (choice == 3) {
            cout << "Quiz Results: " << endl;
            finishedQueue.display();
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
        }
        else {
            cout << "Invalid choice. Try again." <<endl;
        }

    } while (choice != 4);
    
	return 0;
}