int findmax(int arr[],int s,int k){
	int m=-INT_MAX;
	int currentSum=0;
	for(int i=0;i<arr.length();i++){
		currentSum+=arr[i];
		if(i>=k-1){
			m=max(currentSum,m) ;
			currentSum-=arr[i-(k-1)]
		}
	}
	return m;
}

// When we reach the kth element (at index k-1), our window includes elements from index 0 to index k-1, which is exactly k elements.