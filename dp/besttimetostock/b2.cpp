// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.


class Solution {
public:
    int dp[30001][2];
    int solve(vector<int>& prices,int i,int bos){
        if(i==prices.size()) return 0;
        if(dp[i][bos]!=-1) return dp[i][bos];
        int ans=INT_MAX;
        if(bos==0)
            ans=max(-prices[i]+solve(prices,i+1,1),solve(prices,i+1,0));
        else
            ans=max(prices[i]+solve(prices,i+1,0),solve(prices,i+1,1));
        return dp[i][bos]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0);
    }
};