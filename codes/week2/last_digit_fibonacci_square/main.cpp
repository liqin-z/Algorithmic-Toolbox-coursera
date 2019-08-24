#include <iostream>
using namespace std;

unsigned long long sum_fibo(int n) {
    unsigned long long prev = 0, curr = 1, last = 1;
    if (n < 2) return n;
    for (int i = 0; i < n - 1; i++) {
        unsigned long long temprev = prev;
        prev = curr;
        curr += temprev;
//        cout << curr*curr << " ";
        last += (curr*curr % 10);
//        cout << last << " ";
    }
    return last % 10;
}

int main() {
    int n;
    cin >> n;
    cout << sum_fibo(n) << endl;
    return 0;
}