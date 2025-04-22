#include <iostream>
#include <string>

using namespace std;

int super_digit(int n) {
    if (n < 10) return n;

    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return super_digit(sum);
}

int main() {
    string n;
    int k;

    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    int initial_sum = 0;
    for (int i = 0; i < n.length(); i++) {
        initial_sum += n[i] - '0';
    }

    int result = initial_sum * k;
    cout << "Super Digit: " << super_digit(result) << endl;

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
