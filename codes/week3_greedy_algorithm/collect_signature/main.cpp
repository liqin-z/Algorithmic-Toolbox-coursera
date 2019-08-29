#include <algorithm>
#include <iostream>
//#include <climits>
#include <vector>

using namespace std;

struct Segment {
    int start, end;
};

bool safe_remove(vector<Segment> &segments, vector<int> &points) {
    vector<bool> flags(segments.size(), false);
    // if i-th segment contains at least 1 point, then flags.at(i) will be true

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = 0; j < segments.size(); ++j) {
            if (points[i] >= segments[j].start && points[i] <= segments[j].end)
                flags[j] = true;
        }
    }

    for (size_t k = 0; k < segments.size(); ++k) {
        // Check if every segment contains at least 1 point
        if (flags[k]) continue;
        return false;
    }
    return true;
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    vector<bool> flags(segments.size(), false);

    for (size_t i = 0; i < segments.size(); ++i) {
        points.push_back(segments[i].start);
        points.push_back(segments[i].end);
    }
    vector<int> cand = points;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = 0; j < segments.size(); ++j) {
            if (points[i] >= segments[j].start && points[i] <= segments[j].end)
                flags[j] = true;
        }
    }

    vector<int> cnts(points.size(), 0);
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = 0; j < segments.size(); ++j) {
            if (flags[j]) cnts[i]++;
        }
    }

    vector<int> max;
    vector<int> index;

    for (int m = 0; m < points.size(); m++){
        index[m] = m;
    }

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = 0; j < points.size() - i - 1; ++j) {
            if (points.at(j) > points.at(j + 1)) {
                int temp = points[j+1];
                points[j+1] = points[j];
                points[j] = temp;

                int ind_temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = ind_temp;
            }
        }
    }

    for (size_t i = 0; i < points.size(); ++i) {
        max.push_back(points.at(i));
        index.push_back(i);
    }

    return points;
}

// 下面的算法是错的，思路是先把所有线段的起始和终点记录到点坐标，在一个个删掉。
// 但是虽然在删的时候可能的确满足条件 因为你没遍历的点很多 但这不能保证留下的点正确 因为最优的点可能被你之前删掉了
//
//bool safe_remove(vector<Segment> &segments, vector<int> &points) {
//    vector<bool> flags(segments.size(), false);
//    // if i-th segment contains at least 1 point, then flags.at(i) will be true
//
//    for (size_t i = 0; i < points.size(); ++i) {
//        for (size_t j = 0; j < segments.size(); ++j) {
//            if (points[i] >= segments[j].start && points[i] <= segments[j].end)
//                flags[j] = true;
//        }
//    }
//
//    for (size_t k = 0; k < segments.size(); ++k) {
//        // Check if every segment contains at least 1 point
//        if (flags[k]) continue;
//        return false;
//    }
//    return true;
//}
//
//vector<int> optimal_points(vector<Segment> &segments) {
//    vector<int> points;
//    vector<int>::iterator it;
//
//    for (auto &segment : segments) {
//        points.push_back(segment.start);
//        points.push_back(segment.end);
//    }
//
//    vector<int> cand = points;
//    for (it = points.begin(); it != points.end(); it++) {
//        cand.erase(points.begin());
//        if (safe_remove(segments, cand)) {
//            points.erase(it);
//            points.pop_back();
//        }
//    }
//    return points;
//}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].start >> segments[i].end;
    }

    vector<int> points = optimal_points(segments);

    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
    return 0;
}
