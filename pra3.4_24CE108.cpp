#include <iostream>
#include <vector>
using namespace std;

template <typename V>
V find_max(const vector<V>& vec) {
    V maxVal = vec[0];
    for (const auto& elem : vec) {
        if (elem > maxVal) {
            maxVal = elem;
        }
    }
    return maxVal;
}

template <typename V>
void reverse_vector(vector<V>& vec) {
    int n = vec.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(vec[i], vec[n - i - 1]);
    }
}

template <typename V>
void display_vector(const vector<V>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector<int> intvec = {3, 1, 4, 1, 5, 9};
    cout << "int vector: ";
    display_vector(intvec);
    cout << "Max Integer: " << find_max(intvec) << endl;
    reverse_vector(intvec);
    cout << "Reversed Integer vector: ";
    display_vector(intvec);
    cout << endl;

    vector<double> doublevec = {2.5, 3.1, 1.7, 9.8, 4.2};
    cout << "double vector: ";
    display_vector(doublevec);
    cout << "Max Double: " << find_max(doublevec) << endl;
    reverse_vector(doublevec);
    cout << "Reversed Double vector: ";
    display_vector(doublevec);
    cout << endl;

    vector<char> charvec = {'A', 'E', 'X', 'G', 'U'};
    cout << "char vector: ";
    display_vector(charvec);
    cout << "Max Char: " << find_max(charvec) << endl;
    reverse_vector(charvec);
    cout << "Reversed Char vector: ";
    display_vector(charvec);
    cout << endl;

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
