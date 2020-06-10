//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3248/

//solution1: time complexity:O(n)  space complexity:O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev_value = 0;
        int length = 0;
        if (nums.size() >= 1) {
            length = 1;
            prev_value = nums.at(0);
            for (int i = 1; i < nums.size(); ++i) {
                if (prev_value != nums[i]) {
                    nums[length++] = nums[i];
                    prev_value = nums[i];
                }
            }
        }
        return length;
    }
};
