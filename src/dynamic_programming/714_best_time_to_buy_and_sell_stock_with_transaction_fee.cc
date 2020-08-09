//Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//solution: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

//solution1: dp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int days = prices.size();
        vector<vector<int>> dp(days, vector<int>(2, 0));
        
        for (int i = 0; i < days; ++i) {
            if (0 == i) {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }
        }
        
        return days > 0 ? dp[days - 1][0] : 0;
    }
};
