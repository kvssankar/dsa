vector<int>nums;
vector<int>ans(nums.size(),-1);
int n=nums.size();
stack<int>s;
//next greater from right we want so we start from back
for(int i=n-1;i>=0;i--){
    while(!s.empty() && s.top()<=nums[i]){
        s.pop();
    }
    if(s.empty()){
        ans[i]=-1;
    }else{
        ans[i]=s.top();
    }
    s.push(nums[i]);
}
return ans;