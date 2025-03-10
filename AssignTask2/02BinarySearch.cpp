
#include <iostream>
using namespace std;

int binarySearch(const int arr[], int left, int right, int target) {
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int n = std::size(arr);
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1) cout << "Element not found";
    else cout << "Element found at index " << result;
    return 0;
}