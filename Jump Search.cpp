#include <iostream>
#include <cmath>
int jumpSearch(int arr[], int n, int target) {
    // Finding the block size to be jumped
    int step = std::sqrt(n);
    int prev = 0;
    
    // Finding the block where the target element is present
    while (arr[std::min(step, n) - 1] < target) {
        prev = step;
        step += std::sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    
    // Doing a linear search for target in the block beginning with prev
    while (arr[prev] < target) {
        prev++;
        // If we reached next block or end of array, element is not present
        if (prev == std::min(step, n)) {
            return -1;
        }
    }
    
    // If element is found
    if (arr[prev] == target) {
        return prev;
    }
    
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
    cout << "Enter the target element to search for: ";
    cin >> target;
    int result = jumpSearch(arr, n, target);
    
    if (result != -1) {
        stdcout << "Element found at index " << result << "\n";
    } else {
        cout << "Element not found\n";
    }
    return 0;
}
