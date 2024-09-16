#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(vector<pair<int, int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        int keep = 0;
        int end = -1;

        for (const auto& interval : intervals) {
            if (interval.first >= end) {
                end = interval.second;
                keep += 1;
            }
        }

        return intervals.size() - keep;
    }
};
