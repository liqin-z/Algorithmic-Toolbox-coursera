#include <iostream>
using namespace std;

int main(){
    // 1 1 2 3 5 8 13 21 34 55
    int n;
    cin >> n;
    int* fibo = new int[n];
    fibo[0] = 1;
    fibo[1] = 1;

    for (int j = 2; j < n; j++)
        fibo[j] = (fibo[j-1] + fibo[j-2])%10;

    if (n == 0)
        cout << 1 << endl;
    else
        cout << fibo[n-1] << endl;

    delete []fibo;
    return 0;
}