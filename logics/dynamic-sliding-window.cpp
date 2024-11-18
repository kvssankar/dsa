// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int l=0,r=0;
        int n=nums.size();
        int ans=INT_MAX;
        while(l<n){
            if(r<n && sum<target){
                sum+=nums[r];
                r++;
            }else if(sum>=target){ //here r can be greter than end which handles the last case
                ans=min(ans,r-l);
                sum-=nums[l];
                l++;
            }else{
                // current sum is less than num, BUT window's leading edge HAS reached end of array
                // needed to prevent an infinite loop 
                break;
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};