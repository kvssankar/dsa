#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> solve(vector<pair<int, int>>& l0, vector<pair<int, int>>& l1) {
        int i = 0, j = 0;
        vector<pair<int, int>> ans;

        while (i < l0.size() && j < l1.size()) {
            int start = max(l0[i].first, l1[j].first);
            int end = min(l0[i].second, l1[j].second);

            if (start <= end) {
                ans.push_back({start, end});
            }

            if (l0[i].second < l1[j].second) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};
