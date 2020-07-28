//Problem: https://leetcode.com/problems/longest-increasing-subsequence/
//solution:https://mp.weixin.qq.com/s/7QFapCuvi-2nkh6gREcR9g

//solution1: time complexity: O(n)  space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp_arr(size, 1);
	//max_length init to 0, not 1. because empty nums case
        int max_length = 0;
        
        for (int i = 1; i < size; ++i) {
            for (int j = i - 1; j >= 0; --j) {
		//there should been <, not <=
                if (nums[j] < nums[i]) {
                    dp_arr[i] = max(dp_arr[i], dp_arr[j] + 1);
                }
            }
        }
        
        for (int i = 0; i < size; ++i) {
            if (dp_arr[i] > max_length) {
                max_length = dp_arr[i];
            }
        }
        
        return max_length;
    }
};

