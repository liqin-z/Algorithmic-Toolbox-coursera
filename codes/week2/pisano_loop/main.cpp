#include <iostream>

int fibo_module(int n, int m) {
    if (n <= 1) return n;

    auto *fibo = new long long[n];
    fibo[0] = 0, fibo[1] = 1;

    auto *pisano = new long long[10000];
    pisano[0] = 0, pisano[1] = 1;

    for (int j = 2; j < n; ++j)
        fibo[j] = fibo[j - 1] + fibo[j - 2];

    for (int i = 2; i < n; ++i) {
        long long cycle = 0;
        pisano[i] = fibo[i] % m;
        if (pisano[i] == 1 && pisano[i - 1] == 0) {
            cycle = i - 1;
            return pisano[n % cycle];
        }
    }
}

int main(){
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibo_module(n, m) << "\n";
    return 0;
}