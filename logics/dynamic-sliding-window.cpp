// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a contiguous subarray of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int l=0,r=0;
        int n=nums.size();
        int ans=INT_MAX;
        for(r=0;r<n;r++){
            sum+=nums[r];
            while(l<=r && sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};

//what if i want == target

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int sum = 0;
            int l = 0;
            int n = nums.size();
            int ans = INT_MAX;
    
            for (int r = 0; r < n; r++) {
                sum += nums[r];
    
                // Shrink the window only if sum > target
                while (sum > target && l <= r) {
                    sum -= nums[l];
                    l++;
                }
    
                // Check for exact match
                if (sum == target) {
                    ans = min(ans, r - l + 1);
                }
            }
    
            return ans == INT_MAX ? 0 : ans;
        }
    };
    

//https://leetcode.com/problems/max-consecutive-ones-iii/submissions/1456006091/?envType=study-plan-v2&envId=leetcode-75