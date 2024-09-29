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