class Solution {
public:
    bool ok(vector<int>&weights,int days, int maxw){
        int total=0,d=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>maxw){
                return false;
            }
            if(total+weights[i]>maxw){
                total=weights[i];
                d++;
            }
            else{
                total+=weights[i];
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1,r=500*50000;
        int res=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(ok(weights, days, m)){
                res=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
    }
};