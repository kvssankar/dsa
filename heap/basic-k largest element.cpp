//pop remove the top one aka it remove the one with highest priority and highest priority is placed on top
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
#include <iostream>
#include <queue>
using namespace std;

int k = 3;
priority_queue<int, vector<int>, greater<int>> pq; // min-heap

void push(int x) {
    pq.push(x);
    if (pq.size() > k) pq.pop(); // remove smallest if size exceeds k
}

void printTopKUnsorted() {
    priority_queue<int, vector<int>, greater<int>> temp = pq;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

//kth smallest
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        priority_queue<int>pq;
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
#include <iostream>
#include <set>
using namespace std;

int k = 3;
multiset<int> topKSmallest;  // stores k smallest elements

void push(int x) {
    topKSmallest.insert(x);
    if (topKSmallest.size() > k) {
        auto it = prev(topKSmallest.end()); // erase largest
        topKSmallest.erase(it);
    }
}

void printTopKSmallest() {
    for (int val : topKSmallest)
        cout << val << " ";
    cout << endl;
}