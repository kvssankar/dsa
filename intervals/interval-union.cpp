#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> solve(vector<pair<int, int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> ans = {intervals[0]};

        for (const auto& interval : intervals) {
            if (interval.first > ans.back().second) {
                ans.push_back(interval);
            } else {
                ans.back().second = max(ans.back().second, interval.second);
            }
        }

        return ans;
    }
};
