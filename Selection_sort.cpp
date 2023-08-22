 

#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {//loop for elements 
        int minimum = i; // Initialize minimum index with the current 'i'
        for (int j = i + 1; j < n; j++) {//loop to compare the element that we have (minimum) with the 
            //other later elements in the array 
            if (arr[j] < arr[minimum]) {
                minimum = j; // Update minimum index
            }
        }
        // Swap only once after finding the minimum for the current iteration
        swap(arr[i], arr[minimum]);
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selection_sort(n, arr);//we call the functions
    print(arr, n);
    return 0; // Add a return statement to indicate successful program execution
}
