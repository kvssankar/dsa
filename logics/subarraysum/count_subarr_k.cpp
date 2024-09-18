class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int cs=0,ans=0;
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            if(cs==k) ans++;
            ans+=m[cs-k];
            cout<<i<<" "<<cs<<" "<<cs-k<<endl;
            m[cs]++;
        }
        return ans;
    }
};