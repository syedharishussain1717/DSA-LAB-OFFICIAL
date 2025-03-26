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
            this->arr[i] = other.arr[i];
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
                // Shifting elements right
                arr[i] = arr[i - 1]; 
            }
            arr[0] = d;
            currentSize++;
        }
        else {
            cout << "List is full!" << endl;
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

    // Check if the list is empty
    bool Empty() const {

        if (currentSize == 0)
        {
            return true;
        }
        return false;
    }

    // Check if the list is full
    bool full() const {

        if (currentSize == maxSize)
        {
            return true;
        }
        return false;
    }

    // Insert at a given index
    bool insertAt(int index, T value) {
        if (index >= 0 && index <= currentSize && currentSize < maxSize) {
            for (int i = currentSize; i > index; i--) {
                // Shifting elements right
                arr[i] = arr[i - 1]; 
            }
            arr[index] = value;
            currentSize++;
            return true;
        }
        else {
            return false;
        }
    }

    // Get the last element
    T* last() const {

        if (currentSize > 0) {
            T lastElement = arr[currentSize - 1];
            return &lastElement;
        }
        else {
            cout << "List has no last element" << endl;
            T null = nullptr;
            return &null;
        }
    }

    // Search for an element
    bool search(T d) const {
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == d) {
                return true;
            }
        }
        return false;
    }
    int getSize() const { return currentSize; };
};

// Main function
int main() {
    const int size = 5;
    List<int> myList(size);


    myList.addElementAtLastIndex(1);
    myList.addElementAtLastIndex(2);
    myList.addElementAtLastIndex(3);

    myList.removeElementFromEnd();
    cout << "List: ";
    myList.display();

    // menu for lab task 02 
    int choice = 0;
    do
    {
        cout << "Choose any of the following options: " << endl;
        cout << "1.Check whether the list is full or not " << endl;
        cout << "2.Check whether the list is empty or not " << endl;
        cout << "3.Check the currentSize of the List " << endl;
        cout << "4.Search a value in the array: " << endl;
        cout << "5.Insert a value at any index " << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (myList.full()) {
                cout << "List is full!" << endl;
            }
            else {
                cout << "List is not full!" << endl;
            }
            break;
        }

        case 2:
        {
            if (myList.Empty()) {
                cout << "List is empty!" << endl;
            }
            else {
                cout << "List is not empty!" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "The current Size of the array is: " << myList.getSize() << endl;
            break;
        }

        case 4:
        {
            int searchValue;
            cout << "Enter a value to search: ";
            cin >> searchValue;

            if (myList.search(searchValue)) {
                cout << "Element found in the List" << endl;
            }
            else {
                cout << "Element is not found in the List" << endl;
            }
            break;
        }
        case 5:
        {
            int value, idx;
            cout << "Enter a value to insert: ";
            cin >> value;
            cout << "Enter the index to insert: ";
            cin >> idx;

            if (myList.insertAt(idx, value)) {
                cout << "Element inserted in the List" << endl;
                myList.display();
            }
            else {
                cout << "Inserion failed!" << endl;
            }
            break;
        }
        default:
            cout << "PLease enter a valid option" << endl;
            break;
        }

    } while (choice != 0);







    return 0;
}
