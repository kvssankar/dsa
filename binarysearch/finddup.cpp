//only one number is repeated in [1,n] arr length is n+1
// [3,1,3,2]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1;
        int r=nums.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            int c=0;
            for(int i:nums){
                if(i<=m) c++;
            }
            if(c>m){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};