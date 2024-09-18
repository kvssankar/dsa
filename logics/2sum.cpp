class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.count(target-nums[i])){
                return {m[target-nums[i]],i};
            }
            else{
                m[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            if(v[i].first+v[j].first==target)
                return {v[i].second,v[j].second};
            else if(v[i].first+v[j].first<target)
                i++;
            else
                j--;
        }
        return {i,j};
    }
};