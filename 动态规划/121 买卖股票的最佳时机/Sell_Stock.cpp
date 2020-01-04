/*
	Time: 8ms
	Memory: 9.8MB
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0){
            return 0;
        }
        int dp[n][2];
        for (int i = 0; i < n; i++) {
            if (i - 1 == -1) {
                dp[i][0] = 0;
                // 解释：
                //   dp[i][0] 
                // = max(dp[-1][0], dp[-1][1] + prices[i])
                // = max(0, -infinity + prices[i]) = 0
                dp[i][1] = -prices[i];
                //解释：
                //   dp[i][1] 
                // = max(dp[-1][1], dp[-1][0] - prices[i])
                // = max(-infinity, 0 - prices[i]) 
                // = -prices[i]
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        
        return dp[n - 1][0];
    }
    
};
