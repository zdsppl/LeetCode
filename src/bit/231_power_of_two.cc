//Problem: https://leetcode.com/problems/power-of-two/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/chang-yong-de-wei-cao-zuo

//solution:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool res = false;
        if (n <= 0) {
            res = false;
        } else {
            res = (0 == (n & (n - 1)));
        }
        return res;
    }
};
