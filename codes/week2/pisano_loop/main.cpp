#include <iostream>
#include <vector>

long long fibo_module(long long n, long long m) {
    if (n <= 1) return n;

    std::vector<long long> pisano(6 * m);
    pisano[0] = 0, pisano[1] = 1;

    unsigned long long period = 2;
    while (1) {
        pisano[period] = (pisano[period - 1] + pisano[period - 2]) % m;
        if (pisano[period - 1] == 0 && pisano[period] == 1) {
            period--;
            break;
        }
        period++;
    }
    return pisano[n % period];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibo_module(n, m) << "\n";
    return 0;
}