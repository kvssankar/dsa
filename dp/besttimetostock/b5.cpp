// https://leetcode.com/contest/biweekly-contest-158/problems/best-time-to-buy-and-sell-stock-v/

using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

class Solution {
    int n, K;
    vector<ll> prices;
    // dp[i][state][t] 
    // state: 0 = neutral, 1 = holding long, 2 = holding short
    vector<vector<vector<ll>>> memo;
    
    ll dfs(int i, int state, int t) {
        // If we've reached end of days
        if (i == n) {
            // only valid if we're neutral (no open position)
            return state == 0 ? 0 : NEG_INF;
        }
        // If no transactions left
        if (t == 0) {
            // only valid if we're neutral
            return state == 0 ? 0 : NEG_INF;
        }
        ll &res = memo[i][state][t];
        if (res != LLONG_MAX) return res;
        // initialize
        res = NEG_INF;
        
        // Option 1: do nothing / hold current state
        res = max(res, dfs(i+1, state, t));
        
        if (state == 0) {
            // neutral: can open a long or open a short
            // open long: pay prices[i]
            res = max(res, dfs(i+1, 1, t) - prices[i]);
            // open short: receive prices[i]
            res = max(res, dfs(i+1, 2, t) + prices[i]);
        }
        else if (state == 1) {
            // holding long: can close it (sell) and consume one transaction
            res = max(res, dfs(i+1, 0, t-1) + prices[i]);
        }
        else {
            // state == 2, holding short: can close it (buy back) and consume one transaction
            res = max(res, dfs(i+1, 0, t-1) - prices[i]);
        }
        
        return res;
    }

public:
    long long maximumProfit(vector<int>& _prices, int k) {
        prices.assign(_prices.begin(), _prices.end());
        n = prices.size();
        K = k;
        // dp array sized [n][3][K+1], initialize to LLONG_MAX as sentinel
        memo.assign(n, vector<vector<ll>>(3, vector<ll>(K+1, LLONG_MAX)));
        // start at day 0, neutral state, up to k transactions
        return dfs(0, 0, K);
    }
};