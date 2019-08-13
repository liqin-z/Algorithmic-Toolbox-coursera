#include <iostream>
#include <vector>
using namespace std;

int64_t  maxpair(const vector<int64_t>& numbers, int num){
   int64_t cand1 = 0, cand2 = 0;
    for (int i = 0; i < num; ++i) {
        if (numbers[i] > cand2)
            cand2 = numbers[i];
        if (numbers[i] > cand1){
            cand2 = cand1;
            cand1 = numbers[i];
        }
    }
    int64_t result = cand1 * cand2;
    return result;
}

int main() {
    int num;
    cin >> num;
    vector<int64_t> numbers(num);
    for (int i = 0; i < num; ++i) {
        cin >> numbers[i];
    }
    cout << maxpair(numbers, num) << endl;
    return 0;
}