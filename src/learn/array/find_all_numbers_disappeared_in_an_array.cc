//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3270/

//solution1:
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int appear_value = 0;
        int tmp = 0;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (0 != nums[i]) {
                appear_value = nums[i];
                while (0 != appear_value) {
                    tmp = nums[appear_value - 1];
                    nums[appear_value - 1] = 0;
                    appear_value = tmp;
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (0 != nums[i]) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

//solution2:
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (auto i : nums) {
            nums[abs(i) - 1] = -abs(nums[abs(i) - 1]);
        }
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
