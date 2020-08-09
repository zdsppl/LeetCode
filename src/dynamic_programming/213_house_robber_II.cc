//Problem: https://leetcode.com/problems/house-robber-ii/
//solution: https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw

//solution1: dp
class Solution {
public:
    int rob(vector<int>& nums) {
        int houses = nums.size();
        vector<vector<int>> dp(houses, vector<int>(2, 0));
        int max_money = 0;
        int max_money1 = 0;
        int max_money2 = 0;

        if (0 == houses) {
            //do nothing
        } else if (1 == houses) {
            max_money = nums[0];
        } else if (2 == houses) {
            max_money = max(nums[0], nums[1]);
        } else {
            for (int i = 0; i < houses - 1; ++i) {
                if (0 == i) {
                    dp[0][0] = 0;
                    dp[0][1] = nums[0];
                } else {
                    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
                    dp[i][1] = dp[i - 1][0] + nums[i];
                }
            }
            max_money1 = max(dp[houses - 2][0], dp[houses - 2][1]);

            for (int i = 1; i < houses; ++i) {
                if (1 == i) {
                    dp[1][0] = 0;
                    dp[1][1] = nums[1];
                } else {
                    dp[i][0] = max(dp[i - 1][0], dp[i -1][1]);
                    dp[i][1] = dp[i - 1][0] + nums[i];
                }
            }
            max_money2 = max(dp[houses - 1][0], dp[houses - 1][1]);
            max_money = max(max_money1, max_money2);
        }
        
        return max_money;
    }
};
