//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3247/

//solution1: time complexity: O(n)  space complexity: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int highest_index = nums.size() - 1;
        int length = 0;
        
        for (; length <= highest_index; ++length) {
            if (val == nums[length]) {
                //defense case like [3, 2, 2, 3], 3
                //the nums[length] == nums[highest_index]
                while (val == nums[highest_index] && length < highest_index) {
                    --highest_index;
                }
                if (val != nums[highest_index]) {
                    nums[length] = nums[highest_index];
                    nums[highest_index--] = val;
                } else {
                    //if the val == nums[hightest_index], indicate all val has move to the tail
                    break;
                }
            }
        }
        return length;
    }
};
