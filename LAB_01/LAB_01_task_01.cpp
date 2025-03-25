// syed haris hussain shah
// L1F23BSCS0697

// function prototype
void bubbleSort(int arr[], int size);
#include <iostream>
using namespace std;
int main() {

	const int size = 5;
	int arr[size] = { 3,2,1,4,5 };
	cout << "Array before sorting: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	bubbleSort(arr, size);
	cout << endl;
	cout << "Array after sorting: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

// function definition
void bubbleSort(int arr[],int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j +1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			
			}
		}
	}

}