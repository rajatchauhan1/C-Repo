#include <iostream>
#include <vector>
using namespace std;

// Function to perform the merging step of merge sort
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary vector to store sorted elements
    int left = low;    // Left pointer for the left half of the array
    int right = mid + 1; // Right pointer for the right half of the array

    // Merging the two halves into temp in sorted order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) { // Comparing elements from left and right halves
            temp.push_back(arr[left]); // Pushing the smaller element to temp
            left++; // Moving left pointer
        } else {
            temp.push_back(arr[right]);
            right++; // Moving right pointer
        }
    }

    // Copying remaining elements from left half to temp
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copying remaining elements from right half to temp
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copying sorted elements from temp back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive function to perform merge sort
void mergeSort(vector<int> &arr, int low, int high) {
    // Base case: when low equals high, there is only one element in the array
    if (low == high) return;

    // Finding the middle index of the array
    int mid = (low + high) / 2;

    // Recursively sorting the left half
    mergeSort(arr, low, mid);

    // Recursively sorting the right half
    mergeSort(arr, mid + 1, high);

    // Merging the sorted halves
    merge(arr, low, mid, high);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sorting the array using merge sort
    mergeSort(arr, 0, n - 1);

    // Printing the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

