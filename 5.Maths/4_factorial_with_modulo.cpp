#include <iostream>
using namespace std;

const int MOD = 1000000007;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }

    return result;
}

int main() {
    int number;

    cout << "Enter a 3-digit number: ";
    cin >> number;

    if (number < 100 || number > 999) {
        cout << "Please enter a valid 3-digit number." << endl;
        return 1;
    }

    int result = factorial(number);

    cout << "Factorial of " << number << " mod 10^9 + 7 is: " << result << endl;

    return 0;
}
