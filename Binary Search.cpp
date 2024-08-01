#include <iostream>
#include <algorithm>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    // Target is not present in array
    return -1;
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    int arr[n]; 
    
    cout << "Enter the elements of the list (sorted):\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Make sure the array is sorted
    sort(arr, arr + n);
    cout << "Enter the target element to search for: ";
    cin >> target;
    
    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << "\n";
    } else {
        cout << "Element not found\n";
    }
    return 0;
}
