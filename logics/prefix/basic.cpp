class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        
        int left[n];
        int right[n];
        memset(right, 0, sizeof(right));
        memset(left, 0, sizeof(left));
        
        left[0]=nums[0];
        right[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i];
        }

        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+nums[i];
        }

        for(int i=0;i<n;i++){
            if((left[i]-nums[i])==(right[i]-nums[i])) return i;
        }

        return -1;
    }
};