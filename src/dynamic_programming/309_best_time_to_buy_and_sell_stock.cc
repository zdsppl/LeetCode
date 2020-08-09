//Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tuan-mie-gu-piao-wen-ti

//solutio1: dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<vector<int>> dp(days, vector<int>(2, 0));
        
        for (int i = 0; i < days; ++i) {
            if (0 == i) {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
            } else if (1 == i) {
                dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
                dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }
        }
        
        return days > 0 ? dp[days - 1][0] : 0;
    }
};
