//Problme Link:	https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3238/

//solution1:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int32_t consecutive_count = 0;
        int32_t max_consecutive_count = 0;
        for (uint32_t i = 0; i < nums.size(); ++i) {
            if (1 == nums.at(i)) {
                ++consecutive_count;
                if (consecutive_count > max_consecutive_count) {
                    max_consecutive_count = consecutive_count;
                }
            } else {
                consecutive_count = 0;
            }
        }
        return max_consecutive_count;
    }
};
