#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) { for (int i = 0; i < n - 1; i++) {
    int minIndex = i;for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    std::swap(arr[i], arr[minIndex]);
}
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = std::size(arr);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}