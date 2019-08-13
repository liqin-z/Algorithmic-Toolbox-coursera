#include <iostream>
#include <vector>
using namespace std;

int64_t  maxpair(const vector<int64_t>& numbers, int num){
   int64_t cand1 = 0, cand2 = 0;
    for (int i = 0; i < num; ++i) {
        if (numbers[i] > cand2)
            cand2 = numbers[i]; // 防止最后一个数（第二大的数）小于cand1，就先给cand2
        if (numbers[i] > cand1){
            cand2 = cand1; // cand1如果要变，就把之前cand1的值给cand2
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