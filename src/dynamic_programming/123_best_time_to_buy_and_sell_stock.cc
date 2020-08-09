//Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tuan-mie-gu-piao-wen-ti

//solution1: dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        int max_trans = 2;
        vector<vector<vector<int>>> dp(days, vector<vector<int>>(max_trans + 1, vector<int>(2, 0)));
        
        for (int i = 0; i < days; ++i) {
            for (int j = 1; j <= max_trans; ++j) {
                if (0 == i) {
                    dp[0][j][0] = 0;
                    dp[0][j][1] = -prices[0];
                } else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
        
        return days > 0 ? dp[days - 1][max_trans][0] : 0;
    }
};
