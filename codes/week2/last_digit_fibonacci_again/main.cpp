#include <iostream>
using namespace std;

long long sum_fibo(int m, int n) {
    long long last = 0;
    long long fibo[n + 1];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < n + 1; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    for (int j = m; j < n + 1; ++j)
        last += (fibo[j] % 10);
    return last % 10;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << sum_fibo(m, n) << endl;
    return 0;
}