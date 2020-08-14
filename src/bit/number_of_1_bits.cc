//Problem: https://leetcode.com/problems/number-of-1-bits/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/chang-yong-de-wei-cao-zuo

//solution:
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            ++count;
        }
        return count;
    }
};
