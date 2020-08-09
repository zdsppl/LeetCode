//Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tuan-mie-gu-piao-wen-ti

//solution: dp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        int max_profit = 0;
        if (k > days / 2) {
	    //buy and sell need two days, so in days can (buy and sell) days / 2 times at most
	    //so, if k > days / 2, it equal to infinite times
            vector<vector<int>> dp(days, vector<int>(2, 0));
            for (int i = 0; i < days; ++i) {
                if (0 == i) {
                    dp[0][0] = 0;
                    dp[0][1] = -prices[0];
                } else {
                    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
                }
            }
            max_profit = days > 0 ? dp[days - 1][0] : 0;
        } else {
            vector<vector<vector<int>>> 
                dp(days, vector<vector<int>>(k + 1, vector<int>(2, 0)));
            for (int i = 0; i < days; ++i) {
                for (int trans = 1; trans <= k; ++trans) {
                        if (0 == i) {
                        dp[0][trans][0] = 0;
                        dp[0][trans][1] = -prices[i];
                    } else {
                        dp[i][trans][0] = max(dp[i - 1][trans][0], dp[i - 1][trans][1] + prices[i]);
                        dp[i][trans][1] = max(dp[i - 1][trans][1], dp[i - 1][trans - 1][0] - prices[i]);
                    }
                }
            }
            max_profit = days > 0 ? dp[days - 1][k][0] : 0;
        }
        
        return max_profit;
    }
};
