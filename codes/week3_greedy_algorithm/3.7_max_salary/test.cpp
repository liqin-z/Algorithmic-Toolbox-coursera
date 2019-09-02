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

    sort(maxhead.begin(), maxhead.end(), 1);
       cout << "maxhead[i].max" << " " << "maxhead[i].index" << endl;
       for (size_t i = 0; i < maxhead.size(); ++i){
           cout << maxhead[i].max << " || " << maxhead[i].index << " || " << origin[maxhead[i].index] << endl;
       }


    stringstream ss;
    for (size_t i = 0; i < maxhead.size(); ++i) {
        ss << origin[maxhead[i].index];
    }

    string result;
    ss >> result;
    return result;
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
