//Linear Search
#include <iostream>
using namespace std;

int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = std::size(arr);
    int target = 9;
    int result = linearSearch(arr, n, target);
    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }
    return 0;
}