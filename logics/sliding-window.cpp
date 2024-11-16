class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0,avg=INT_MIN,start=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(i-start+1==k){
                avg=max(avg,sum/(double)k);
                sum-=nums[start++];
            }
        }
        return avg;
    }
};