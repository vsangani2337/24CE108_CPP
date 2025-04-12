#include <iostream>
#include <vector>
using namespace std;

int recursiveSum(const vector<int>& arr, int index) {
    if (index < 0)
        return 0;
    return arr[index] + recursiveSum(arr, index - 1);
}

int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int val : arr) {
        sum += val;
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    vector<int> numbers(size);
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int sumRecursive = recursiveSum(numbers, size - 1);
    int sumIterative = iterativeSum(numbers);

    cout << "Sum using recursion: " << sumRecursive << endl;
    cout << "Sum using iteration: " << sumIterative << endl;

    cout <<"24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
