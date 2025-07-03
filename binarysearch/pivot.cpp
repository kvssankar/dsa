// 3 5 1 2 3

int l=0;
int r=n-1;
//wont work for dups
while(l<=r){
    int m=l+(r-l)/2;
    int next=(m+1)%n;
    int prev=(m-1+n)%n;
    if(arr[m]<=arr[next] && arr[m]<=arr[prev]){
        return mid;
    }
    if(arr[l]<=arr[m]){
        l=m+1;
    }
    else{
        r=m-1;
    }
}



 int n  = static_cast<int>(nums.size());
        int lo = 0, hi = n - 1;

        int pivotCandidate = lo;               // some minimum value

        /* 2️⃣  Ensure we pick the *first* minimum that follows the drop.
               (Handles “… 2, 1, 1, 1 …” where the first min sits at index 0.)   */
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {       // real rotation point
                pivotCandidate = i;
                break;
            }
        }
        return pivotCandidate;     