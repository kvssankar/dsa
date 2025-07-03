// 3 5 1 2 3
 //    m
 int l=0;
        int r=n-1;
       
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]){
                l=m+1;
            }else if(nums[m]<nums[r]){
                r=m;
            }else{
                r--;
            }
        }