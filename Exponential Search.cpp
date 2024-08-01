#include <iostream>
#include <algorithm>
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow
        
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int target) {
    // If the target is present at the first location
    if (arr[0] == target) {
        return 0;
    }
    
    // Find range for binary search by repeated doubling
    int bound = 1;
    while (bound < n && arr[bound] < target) {
        bound *= 2;
    }   
    // Call binary search for the found range
    return binarySearch(arr, bound / 2, std::min(bound, n - 1), target);
}
int main() {
    int n, target;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the list (sorted):\n";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the target element to search for: ";
    cin >> target;
    int result = exponentialSearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << "\n";
    } else {
       cout << "Element not found\n";
    }
    return 0;
}
