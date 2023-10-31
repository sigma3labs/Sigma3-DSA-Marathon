#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int medianOfThree(vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);

    return mid;
}

int partition(vector<int>& arr, int left, int right) {
    int pivotIndex = medianOfThree(arr, left, right);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); 
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); 
    return i + 1;
}

void introsortUtil(vector<int>& arr, int left, int right, int depthLimit) {
    while (right - left > 16) {
        if (depthLimit == 0) {
            make_heap(arr.begin() + left, arr.begin() + right + 1);
            sort_heap(arr.begin() + left, arr.begin() + right + 1);
            return;
        }
        else {
            int pivotIndex = partition(arr, left, right);
            introsortUtil(arr, pivotIndex + 1, right, depthLimit - 1);
            right = pivotIndex - 1;
        }
    }
    insertionSort(arr, left, right);
}

void introsort(vector<int>& arr) {
    int depthLimit = 2 * log(arr.size());
    introsortUtil(arr, 0, arr.size() - 1, depthLimit);
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {23, 10, 20, 5, 7};
    cout << "Original array: ";
    printArray(arr);

    introsort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
