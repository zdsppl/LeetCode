//Problem: https://leetcode.com/problems/house-robber/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/qiang-fang-zi

//solution1: dp
class Solution {
public:
    int rob(vector<int>& nums) {
        int houses = nums.size();
        int max_money = 0;
        vector<vector<int>> dp(houses, vector<int>(2, 0));
        
        if (houses > 0) {
            for (int i = 0; i < houses; ++i) {
                if (0 == i) {
                    dp[0][0] = 0;
                    dp[0][1] = nums[0];
                } else {
                    dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
                    dp[i][1] = dp[i - 1][0] + nums[i];
                }
            }
            
            max_money = max(dp[houses -1][0], dp[houses - 1][1]);
        }
        
        return max_money;
    }
};
