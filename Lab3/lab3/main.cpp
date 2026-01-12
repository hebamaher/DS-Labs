#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // assume the first element is the minimum

        // Find the index of the minimum element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        //array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy any remaining elements
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // pivot is the last element
    int i = low - 1;         // index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // place pivot in the correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;  // return pivot index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   // sort left part
        quickSort(arr, pi + 1, high);  // sort right part
    }
}


int binarySearchIterative(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return 1;

        if (target < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;   // not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    if (target < arr[mid])
        return binarySearchRecursive(arr, left, mid - 1, target);
    else
        return binarySearchRecursive(arr, mid + 1, right, target);
}

void sortMatrix(int mat[][100], int m, int n) {
    int size = m * n;
    int arr[10000];

    // flatten matrix
    int k = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            arr[k++] = mat[i][j];

    sort(arr, arr + size);

    k = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = arr[k++];
}

void printMatrix(int mat[][100], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

map<int,int> freq;
bool compare(int a, int b) {
    if (freq[a] == freq[b])
        return a < b;
    return freq[a] > freq[b];
}

int main() {
//    int arr[] = {64, 25, 12, 22, 11};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    selectionSort(arr, n);
//    bubbleSort(arr, n);
//    mergeSort(arr, 0, n - 1);
//    quickSort(arr, 0, n - 1);
//
//    cout << "Sorted array: ";
//    for (int i=0; i<n; i++) {
//        cout << arr[i] << " ";
//    }
//
//    int target = 64;
//
//    cout << "Iterative result: "
//         << binarySearchIterative(arr, n, target) << endl;
//
//    cout << "Recursive result: "
//         << binarySearchRecursive(arr, 0, n - 1, target) << endl;


    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    sort(arr, arr+n, compare);

    cout << "\nSorted by Frequency:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}
