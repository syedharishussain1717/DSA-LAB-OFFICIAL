// SYED HARIS HUSSAIN SHAH 
// L1F23BSCS0697

#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    T* arr;       
    int maxSize;    
    int currentSize; 

public:
    // Parameterized constructor
    List(int size) {
        this->maxSize = size;
        this->currentSize = 0;
        this->arr = new T[maxSize];  
    }

    // Copy Constructor
    List(const List& other) {
        this->maxSize = other.maxSize;
        this->currentSize = other.currentSize;
        this->arr = new T[maxSize];
        for (int i = 0; i < currentSize; i++) {
           arr[i] = other.arr[i];
        }
    }

    // Destructor 
    ~List() {
        delete[] arr;
    }

    // Add element at the first index
    void addElementAtFirstIndex(T d) {
        if (currentSize < maxSize) {
            for (int i = currentSize; i > 0; i--) {
                arr[i] = arr[i - 1]; 
            }
            arr[0] = d;
            currentSize++;
        }
        else {
            cout << "List is full!." << endl;
        }
    }

    // Add element at the last index
    void addElementAtLastIndex(T d) {
        if (currentSize < maxSize) {
            arr[currentSize] = d;
            currentSize++;
        }
        else {
            cout << "List is full!" << endl;
        }
    }

    // Remove element from the last index
    void removeElementFromEnd() {
        if (currentSize > 0) {
            // removing elem form the last index 
            arr[currentSize] = 0;
            currentSize--;
        }
        else {
            cout << "List is empty!" << endl;
        }
    }

    // Remove element from the first index
    void removeElementFromStart() {
        if (currentSize > 0) {
            for (int i = 0; i < currentSize - 1; i++) {
                arr[i] = arr[i + 1]; 
            }
            currentSize--;
        }
        else {
            cout << "List is empty!" << endl;
        }
    }

    //  function for displaying  elements
    void display() const {
        if (currentSize == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
};

// Main function
int main() {
    const int size = 5;
    List<int> myList(size);

    // ADDING ELEMENTS AT THE LAST 
    myList.addElementAtLastIndex(1);
    myList.addElementAtLastIndex(2);
    myList.addElementAtLastIndex(3);

    // REMOVING ELEMENTS FROM THE END 
    myList.removeElementFromEnd();

    // ADDING ELEMENT AT THE START
    myList.addElementAtFirstIndex(0);
    myList.display();

    // Using copy constructor
    cout << "Calling copy constructor" << endl;
    List<int> myList2(myList);
    myList2.display();

    
    return 0;
}
