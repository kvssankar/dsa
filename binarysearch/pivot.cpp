// 3 5 1 2 3

int l=0;
int r=n-1;

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