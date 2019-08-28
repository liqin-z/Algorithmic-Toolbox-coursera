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

    for (size_t i = 0; i < 2 * segments.size(); ++i) {
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
    vector<int>::iterator it;

    for (auto &segment : segments) {
        points.push_back(segment.start);
        points.push_back(segment.end);
    }

    vector<int> cand = points;
    for (it = points.begin(); it != points.end(); it++) {
        cand.erase(points.begin());
        if (safe_remove(segments, cand)) {
            points.erase(it);
            points.pop_back();
        }
    }
    return points;
}

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
