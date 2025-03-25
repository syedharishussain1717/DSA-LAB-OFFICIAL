// syed haris hussain shah
// L1F23BSCS0697
#include <iostream>
using namespace std;

//function prototype
int binarySearch(int arr[], int size, int target);
int main() {
    const int size = 6;
    int arr[size] = { 1, 3, 5, 7, 9, 11 };
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    }else {
        cout << "Element not found" << endl;

    }
        
    return 0;
}
// function definition
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;  

        if (arr[mid] == target) { return mid; }  
           
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }  
       
    }
    return -1; 
}
