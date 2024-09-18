//only one dup, one missing - 1,3,3,2,5
vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    int n=arr.size();
    for(int i=0;i<n;i++){
        swap(arr[i],arr[arr[i]-1]);
    }
    for(int i=0;i<n;i++){
        if(i+1!=arr[i]){
            return {min(i,arr[i]),max(i,arr[i])};
        }
    }
    return {-1,-1};
}


