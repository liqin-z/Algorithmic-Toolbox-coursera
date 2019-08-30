#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/* --------------------------------- PROBLEM DESCRIPTION ---------------------------------- *
 * TASK: The goal of this code problem is to implement an algorithm for the                 *
 *       fractional knapsack problem.                                                       *
 *                                                                                          *
 * Input Format: The first line of the input contains the number n of items and             *
 *               the capacity W of a knapsack. The next n lines define the values           *
 *               and weights of the items. The i-th line contains integers vi and           *
 *               wi, the value and the weight of i-th item, respectively.                   *
 *                                                                                          *
 * Constraints: 1 <= n <= 1000,0 <= W <= 2*10^6, 0 <= vi <= 2*10^6, 0 < wi <= 2*10^6        *
 *              for all 1 <= i <= n. All the numbers are integers.                          *
 *                                                                                          *
 * Output Format: Output the maximal value of fractions of items that fit into the          *
 *                knapsack. The absolute value of the difference between the answer         *
 *                of your program and the optimal value should be at most 10−3.             *
 *                                                                                          *
 *                To ensure this, output your answer with at least four digits after        *
 *                the decimal point (otherwise your answer, while being computed correctly, *
 *                can turn out to be wrong because of rounding issues).                     *
 * ---------------------------------------------------------------------------------------- */

void BubbleSort(double *p, int size, int *indices) {
    for (int m = 0; m < size; m++) {
        indices[m] = m;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                double temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                int ind_temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = ind_temp;
            }
        }
    }
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int size = weights.size();
    int indices[size];
    double unit[size];
    int curr_capacity = 0;

    for (int j = 0; j < size; ++j)
        unit[j] = (double)values[j] / weights[j]; // restore the unit value

    BubbleSort(unit, size, indices);
//    for (int i = size-1; i > -1; --i) {
//        cout << "value: " << unit[i] << " Index: " << indices[i] << endl;
//    }

    while (curr_capacity <= capacity) {
        for (int i = size - 1; i > -1; --i) {
            if ((capacity - curr_capacity) >= weights[indices[i]]) {
                value += (unit[i] * weights[indices[i]]);
                curr_capacity += weights[indices[i]];
            } else {
                value += (unit[i] * (capacity - curr_capacity));
                curr_capacity = capacity + 1;
            }
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        cin >> values[i] >> weights[i];

    double optimal_value = get_optimal_value(capacity, weights, values);
    cout << fixed << setprecision(4) << optimal_value << endl;
    return 0;
}
