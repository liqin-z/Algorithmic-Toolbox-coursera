#include <iostream>
using namespace std;

int gcd_helper(int a, int b) {
    if (a % b == 0)
        return b;
    else if (b % a == 0)
        return a;
    else if (a % b == 1 || b % a == 1)
        return 1;
    else if (a > b)
        return gcd_helper(a % b, b);
    else
        return gcd_helper(a, b % a);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd_helper(a,b) << endl;
    return 0;
}