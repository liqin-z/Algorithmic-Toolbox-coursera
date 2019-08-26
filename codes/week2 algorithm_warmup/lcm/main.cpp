#include <iostream>
using namespace std;

int64_t gcd_helper(int64_t a, int64_t b) {
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
    // The fastest way to find lcm of a and b is to use a*b/gcd(a,b)
    int64_t a, b;
    cin >> a >> b;
    cout << a * b / gcd_helper(a, b) << endl;
    return 0;
}