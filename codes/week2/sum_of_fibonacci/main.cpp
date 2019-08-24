#include <iostream>
using namespace std;

long long sum_fibo(int n){
    long long prev = 0, curr = 1, last = 1;
    if (n < 2) return n;
    for (int i = 2; i <= n; i++) {
        long long temprev = prev;
        prev = curr;
        curr += temprev;
//        cout << "curr: " << curr << " ";
        last += curr;
//        cout << "last: " << last << " ";
    }
    return last % 10; // 方法不够高效 和好像是错的
}

int main() {
    int n;
    cin >> n;
    cout << sum_fibo(n) << endl;
    return 0;
}