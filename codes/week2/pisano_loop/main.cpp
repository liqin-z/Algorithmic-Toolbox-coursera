#include <iostream>
#include <vector>

long long fibo_module(long long n, long long m) {
    if (n <= 1) return n;
    long long cycle = 0;

    std::vector<long long> pisano(10000);
    pisano[0] = 0, pisano[1] = 1;

    for (long long j = 2; j < n; ++j)
        pisano[j] = (pisano[j - 1] + pisano[j - 2]) % m;

    for (long long i = 2; i < n; ++i) {
        if (pisano[i] == 0 && pisano[i + 1] == 1) {
            cycle = i;
            break;
        }
    }
    return pisano[n % cycle];
}

int main(){
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibo_module(n, m) << "\n";
    return 0;
}