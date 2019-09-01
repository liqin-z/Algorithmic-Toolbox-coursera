#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

struct number{
    int max;
    int index;
};

string largest_number(vector<string> a) {
    int num = 0;
    vector<int> origin(a.size());
    vector<number> maxhead(a.size());
    for (size_t j = 0; j < a.size(); ++j) {
        num += a[j].length();
    }

    for (int j = 0; j < a.size(); ++j) {
        int cand = stoi(a[j]);
        origin[j] = cand;
        while (cand >= 10) {
            cand /= 10;
        }
        maxhead[j].index = j;
        maxhead[j].max = cand;
    }

    // Bubble (被sort快排代替了)
//    for (int i = 0; i < a.size(); i++) {
//        for (int j = 0; j < a.size() - i - 1; j++) {
//            if (maxhead[j].max < maxhead[j + 1].max) {
//                int temp = maxhead[j].max;
//                maxhead[j].max = maxhead[j + 1].max;
//                maxhead[j + 1].max = temp;
//            }
//        }
//    }

    sort(maxhead.begin(), maxhead.end(), [](const number &x, const number &y) -> bool { return x.max > y.max; });
    for (size_t i = 0; i < maxhead.size(); ++i) {
        for (size_t j = 0; j < maxhead.size() - i - 1; ++i) {
            if (maxhead[j].max == maxhead[j + 1].max) {
                string a = to_string(origin[maxhead[i].index]);
                string b = to_string(origin[maxhead[i + 1].index]);
                if (stoi(a + b) < stoi(b + a)) {
                    int temp_index = maxhead[j].index;
                    maxhead[j].index = maxhead[j + 1].index;
                    maxhead[j + 1].index = temp_index;
                }
            }
        }
    }

//    cout << "maxhead[i].max" << " " << "maxhead[i].index" << endl;
//    for (size_t i = 0; i < maxhead.size(); ++i){
//        cout << maxhead[i].max << " || " << maxhead[i].index << " || " << origin[maxhead[i].index] << endl;
//    }

    stringstream ss;
    for (size_t i = 0; i < maxhead.size(); ++i) {
        ss << origin[maxhead[i].index];
    }

    string result;
    ss >> result;
    return result;

    // 按单个数字进行最大化排序
//    vector<int> all;
//    for (size_t j = 0; j < a.size(); ++j) {
//        for (int i = 0; i < a[j].length(); ++i) {
//            int k = a[j][i] - 48; // char to int
//            all.push_back(k);
//        }
//    }
//    sort(all.begin(), all.begin() + num, greater<int>()); // definitely plausible

//    sort(all.begin(), all.begin() + num, [](int x, int y) -> bool {return x > y;});
//
//    stringstream result;
//    copy(all.begin(), all.end(), ostream_iterator<int>(result));
//
//    string re;
//    result >> re;
//    return re;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    cout << largest_number(a) << '\n';
    return 0;
}
