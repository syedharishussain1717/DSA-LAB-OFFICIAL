// syed haris hussain shah
// L1F23BSCS0697

// function prototype
bool linearSearch(int arr[], int size, int key);
#include <iostream>
using namespace std;
int main() {

	const int size = 5;
	int arr[size] = { 3,2,1,4,5 };
	int key;
	cout << "Enter the element to Search in the Array: ";
	cin >> key;
	
	cout << endl;
	if (linearSearch(arr, size, key))
	{
		cout << "Element found in the array!" << endl;
	}
	else {
		cout << "Element does not found in the array" << endl;
	}
	
	return 0;
}

// function definition
bool linearSearch( int arr[],int size, int key) {
     
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return true;
		}
	}
	return false;
}