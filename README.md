# dsa

https://leetcode.com/studyplan/leetcode-75/

lower bound = >=
upper_bound = >
int idx = lower_bound(vec.begin(), vec.end(), qi) - vec.begin();
int nextIdx = (idx + 1) % sz;
int prevIdx = (idx - 1 + sz) % sz;©leetcode

 // Set with greatest elements on top (descending order)
set<int, greater<int>> s;

#include <iostream>
#include <set>
#include <numeric> // for accumulate
using namespace std;

int main() {
    set<int> s = {1, 2, 3, 4, 5};
    int sum = accumulate(s.begin(), s.end(), 0);

    cout << "Sum: " << sum << endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    int start = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == delimiter) {
            result.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }

    // Add the last part
    result.push_back(str.substr(start));

    return result;
}
