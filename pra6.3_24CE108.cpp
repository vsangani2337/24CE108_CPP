#include <iostream>
using namespace std;

void merge_sorted_arrays(int* arr1, int n, int* arr2, int m, int*& merged_arr, int& merged_size) {
    merged_size = n + m;
    merged_arr = new int[merged_size];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            merged_arr[k++] = arr1[i++];
        } else {
            merged_arr[k++] = arr2[j++];
        }
    }

    while (i < n) {
        merged_arr[k++] = arr1[i++];
    }

    while (j < m) {
        merged_arr[k++] = arr2[j++];
    }
}

int main() {
    int n, m;

    cout << "Enter size of first sorted array: ";
    cin >> n;
    int* arr1 = new int[n];

    cout << "Enter " << n << " elements (sorted): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> m;
    int* arr2 = new int[m];

    cout << "Enter " << m << " elements (sorted): ";
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    int* merged_arr;
    int merged_size;

    merge_sorted_arrays(arr1, n, arr2, m, merged_arr, merged_size);

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < merged_size; ++i) {
        cout << merged_arr[i] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merged_arr;

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
