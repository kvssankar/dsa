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

//https://leetcode.com/problems/max-consecutive-ones-iii/submissions/1456006091/?envType=study-plan-v2&envId=leetcode-75