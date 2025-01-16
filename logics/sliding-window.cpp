int findMax(int arr[], int n, int k) {
    int maxSum = INT_MIN; // To track the maximum sum
    int currentSum = 0;   // To track the current window sum
    int start = 0;        // Start index of the window

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        if (i - start + 1 == k) {
            maxSum = max(maxSum, currentSum);
            currentSum -= arr[start];
            start++;
        }
    }

    return maxSum;
}