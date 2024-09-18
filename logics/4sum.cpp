class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=j+1,b=n-1;
                long long int t=(long long)target-(long long)nums[i]-(long long)nums[j];
                while(a<b){
                    long long int sum=nums[a]+nums[b];
                    if(sum==t){
                        ans.push_back({nums[i],nums[j],nums[a],nums[b]});
                        while(a<b && ans.back()[2]==nums[a]) a++;
                    }
                    else if(sum>t){
                        b--;
                    }
                    else{
                        a++;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};