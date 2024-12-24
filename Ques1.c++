#include <iostream>
using namespace std;

int sumOfNaturalNumbers(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n > 0) {
        int result = sumOfNaturalNumbers(n);
        cout << "The sum of all natural numbers from 1 to " << n << ": " << result << endl;
    } else {
        cout << "Please enter a positive integer." << endl;
    }

    return 0;
}