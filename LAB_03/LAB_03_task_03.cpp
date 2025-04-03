// SYED HARIS HUSSAIN SHAH
// L1F23BSCS0697

#include <iostream>
using namespace std;

template <typename Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;
public:
    // default constructor
    List() : arr(nullptr), maxSize(0), currentSize(0) {}

    // parameterized constructor 
    List(int maxSize) {
        this->maxSize = maxSize;
        this->arr = new Type[this->maxSize];
        this->currentSize = 0;
    }

    // deep copy constructor 
    List(const List& obj) {
        this->maxSize = obj.maxSize;
        this->arr = new Type[obj.maxSize];
        for (int i = 0; i < maxSize; i++) {
            this->arr[i] = obj.arr[i];
        }
        this->currentSize = obj.currentSize;
    }

    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    // destructor to free memory
    ~List() {
        delete[] this->arr;
    }
};

template <typename T>
class CustomList : public List<T> {
public:
    CustomList(int size) : List<T>(size) {}

    void addElementAtFirstIndex(T elem) {
        if (this->currentSize != this->maxSize) {

            this->currentSize++;
            for (int i = this->currentSize; i > 0; i--) {
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[0] = elem;
         
            cout << "Element added at first index " << endl;
        }
        else {
            cout << "List is full " << endl;
        }
    }

    void addElementAtLastIndex(T elem) {
        if (this->currentSize != this->maxSize) {
            this->arr[this->currentSize++] = elem;
            cout << "Element added at last index " << endl;
        }
        else {
            cout << "List is full" << endl;
        }
    }

    T removeElementFromEnd() {
        if (this->currentSize != 0) {
            T removedElement = this->arr[this->currentSize - 1];
            this->currentSize--;
            cout << "Element removed from end " << endl;
            return removedElement;
        }
        else {
            cout << "List is Empty " << endl;
            T null = 0;
            return null;
        }
    }

    void removeElementFromStart() {
        if (this->currentSize != 0) {
            for (int i = 0; i < this->currentSize - 1; i++) {
                this->arr[i] = this->arr[i + 1];
            }
            this->currentSize--;
            cout << "Element removed from start " << endl;
        }
        else {
            cout << "List is already Empty " << endl;
        }
    }

    void display() {
        for (int i = 0; i < this->currentSize; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
    T sumOfPrimes() {
        T sumPrime = 0;
        
        for (int i = 0; i < this->currentSize; i++)
        {
            bool isPrime = true;
            for (int j = 2; j < this->arr[i]; j++)
            {
                if (this->arr[i] % j == 0)
                {
                    isPrime = false;
                }
            }
            if (isPrime)
            {
                sumPrime += this->arr[i];
            }
        }
        return sumPrime;
    }
    T secondMaxEven() {
        T firstMax = 0;
        T secondMax = 0;
        for (int i = 0; i < this->currentSize; i++)
        {
            if ((this->arr[i] % 2 == 0) && (this->arr[i] > firstMax))
            {
                    firstMax = this->arr[i]; 
            }
        }
        for (int j = 0; j < this->currentSize; j++)
        {
            if ((this->arr[j] % 2 == 0) && (this->arr[j] < firstMax) && (this->arr[j] > secondMax))
            {
                secondMax = this->arr[j];
            }
        }
        return secondMax;
    }
    T secondMinOdd() {
        T firstMinOdd = this->arr[0];
        T secondMinOdd = this->arr[0];
        for (int i = 0; i < this->currentSize; i++)
        {
            if ((this->arr[i] % 2 != 0) && (this->arr[i] < firstMinOdd))
            {
                firstMinOdd = this->arr[i];
            }
        }
        for (int j = 0; j < this->currentSize; j++)
        {
            if ((this->arr[j] % 2 == 0) && (this->arr[j] < firstMinOdd) && (this->arr[j] > secondMinOdd))
            {
                secondMinOdd = this->arr[j];
            }
        }
        return secondMinOdd;
    }
    void printDuplicates() {
        cout << "Duplicates are: ";
        for (int i = 0; i < this->currentSize; i++)
        {
            for (int j = i + 1; j < this->currentSize; j++)
            {
                if (this->arr[i] == this->arr[j])
                {
                    cout << this->arr[i] << " ";
                }
            }
        }
        cout << endl;
    }
    void rotateClockwaise(int r) {
        /*T temp = this->arr[this->currentSize - 1];
 
        for (int i = this->currentSize - 1; i < 0; i--)
        {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[0] = temp;
        CustomList::display();*/
    }
};

int main() {
    int size = 5;
    CustomList<int> list(size);
    list.addElementAtLastIndex(1);
    list.addElementAtLastIndex(2);
    list.addElementAtLastIndex(3);
    list.addElementAtLastIndex(4);
    list.addElementAtLastIndex(3);
    list.display();
    /*   cout << "Removing element from start" << endl;
       list.removeElementFromStart();
       list.display();
       cout << "Removing element from end" << endl;
       list.removeElementFromEnd();
       list.display();*/
    cout << "Sum of primes: " << list.sumOfPrimes() << endl;
    cout << "Second Maximum Even Number: " << list.secondMaxEven() << endl;
    cout << "Second Minimum Odd Number: " << list.secondMinOdd() << endl;
    // printing duplicates
    list.printDuplicates();
    list.display();
    //cout << "rotated clockwise: ";
  
    //list.rotateClockwaise(1);
   
    return 0;
}
