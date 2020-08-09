//problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tuan-mie-gu-piao-wen-ti

//solution1: dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            if (0 == i) {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], -prices[i]);
            }
        }
        return n > 0 ? dp[n-1][0] : 0;
    }
};

//solution2: [7, 1, 5, 3, 6, 4]. N6 - N3 + N3 - N5 + N5 - N1 = N6 - N1 = 5

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int curr_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            curr_profit = max(0, curr_profit += prices[i] - prices[i - 1]);
            max_profit = max(max_profit, curr_profit);
        }
        return max_profit;
    }
};
