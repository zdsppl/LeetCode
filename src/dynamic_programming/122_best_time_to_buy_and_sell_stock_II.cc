//Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//solution1:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int curr_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            curr_profit = max(0, curr_profit += prices[i] - prices[i - 1]);
            if (curr_profit > 0) {
                max_profit += curr_profit;
                curr_profit = 0;
            }
        }
        
        return max_profit;
    }
};
