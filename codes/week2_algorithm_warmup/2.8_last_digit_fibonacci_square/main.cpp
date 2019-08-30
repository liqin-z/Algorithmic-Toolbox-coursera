#include <iostream>
using namespace std;

unsigned long long sum_fibo(unsigned long long n) {
    n = n % 60;
    auto *fib = new unsigned long long[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (unsigned long long i = 2; i < n + 1; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }

    return fib[n];
}

int main() {
    unsigned long long n;
    cin >> n;
    cout << sum_fibo(n+1) * sum_fibo(n) % 10 << endl;
    return 0;
}