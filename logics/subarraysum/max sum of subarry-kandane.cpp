//find max sum of subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0], ans = nums[0];
        for(int i=1;i<nums.size();i++){
            temp = max(temp+nums[i],nums[i]);
            ans = max(ans,temp);
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp=nums[0],ans= nums[0],start=0,end=0;
        for(int i=1;i<nums.size();i++){
            if(temp+nums[i]<nums[i]){
                start=i;
            }
            temp=max(temp+nums[i],nums[i]);
            if(temp>ans){
                end=i;
                ans=temp;
            }
        }
        cout<<start<<" "<<end<<endl;
        return ans;
    }
};