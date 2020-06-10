//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/

//solution1: time complexity:O(n)  space complexity:O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool ret = false;
        if (A.size() >= 3) {
            int mountain_top = -1;
            for (int i = 0; i < A.size(); ++i) {
                if (0 == i) {
                    //do nothing
                    continue;
                } else if (!(A[i] > A[i-1])){
                    mountain_top = i - 1;
                    break;
                }
            }
            
            if (mountain_top > 0 && mountain_top < A.size() - 1) {
                ret = true;
                for (int i = mountain_top + 1; i < A.size(); ++i) {
                    if (A[i] >= A[i - 1]) {
                        ret = false;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};
