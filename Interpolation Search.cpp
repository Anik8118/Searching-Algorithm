#include <iostream>
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Estimate the position of the target element
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        // Target found
        if (arr[pos] == target) {
            return pos;
        }   
        // If target is larger, target is in the right sub-array
        if (arr[pos] < target) {
            low = pos + 1;
        }
        // If target is smaller, target is in the left sub-array
        else {
            high = pos - 1;
        }
    }   
    return -1; // Target not found
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
    int result = interpolationSearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << "\n";
    } else {
        cout << "Element not found\n";
    }
    return 0;
}
