#include <iostream>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Return -1 if the target element is not found
}

int main() {
    int n, target;
    
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    
    cout << "Enter the elements of the list:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << "Enter the target element to search for: ";
    cin >> target;
    
    int result = linearSearch(arr, n, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << "\n";
    } else {
        cout << "Element not found\n";
    }
    return 0;
}
