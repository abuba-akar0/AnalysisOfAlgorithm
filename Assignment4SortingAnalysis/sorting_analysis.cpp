#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort Helpers
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to measure average execution time over multiple runs
double measureAverageTime(void (*sortFunc)(int[], int), int arr[], int n, int runs = 5) {
    double totalTime = 0.0;
    int temp[n];
    for (int i = 0; i < runs; i++) {
        copy(arr, arr + n, temp); // Copy array to avoid modifying the original
        auto start = chrono::high_resolution_clock::now();
        sortFunc(temp, n);
        auto end = chrono::high_resolution_clock::now();
        totalTime += chrono::duration<double, milli>(end - start).count();
    }
    return totalTime / runs;
}

double measureAverageTimeMergeSort(void (*sortFunc)(int[], int, int), int arr[], int n, int runs = 5) {
    double totalTime = 0.0;
    int temp[n];
    for (int i = 0; i < runs; i++) {
        copy(arr, arr + n, temp); // Copy array to avoid modifying the original
        auto start = chrono::high_resolution_clock::now();
        sortFunc(temp, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();
        totalTime += chrono::duration<double, milli>(end - start).count();
    }
    return totalTime / runs;
}

int main() {
    cout << fixed << setprecision(4);

    // Arrays
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

    // Sorting and timing
    cout << "\nBubble Sort:\n";
    cout << "Arr1: " << measureAverageTime(bubbleSort, arr1, 5) << " ms\n";
    cout << "Arr2: " << measureAverageTime(bubbleSort, arr2, 10) << " ms\n";
    cout << "Arr3: " << measureAverageTime(bubbleSort, arr3, 50) << " ms\n";
    cout << "Arr4: " << measureAverageTime(bubbleSort, arr4, 100) << " ms\n";

    cout << "\nSelection Sort:\n";
    cout << "Arr1: " << measureAverageTime(selectionSort, arr1, 5) << " ms\n";
    cout << "Arr2: " << measureAverageTime(selectionSort, arr2, 10) << " ms\n";
    cout << "Arr3: " << measureAverageTime(selectionSort, arr3, 50) << " ms\n";
    cout << "Arr4: " << measureAverageTime(selectionSort, arr4, 100) << " ms\n";

    cout << "\nInsertion Sort:\n";
    cout << "Arr1: " << measureAverageTime(insertionSort, arr1, 5) << " ms\n";
    cout << "Arr2: " << measureAverageTime(insertionSort, arr2, 10) << " ms\n";
    cout << "Arr3: " << measureAverageTime(insertionSort, arr3, 50) << " ms\n";
    cout << "Arr4: " << measureAverageTime(insertionSort, arr4, 100) << " ms\n";

    cout << "\nMerge Sort:\n";
    cout << "Arr1: " << measureAverageTimeMergeSort(mergeSort, arr1, 5) << " ms\n";
    cout << "Arr2: " << measureAverageTimeMergeSort(mergeSort, arr2, 10) << " ms\n";
    cout << "Arr3: " << measureAverageTimeMergeSort(mergeSort, arr3, 50) << " ms\n";
    cout << "Arr4: " << measureAverageTimeMergeSort(mergeSort, arr4, 100) << " ms\n";

    return 0;
}