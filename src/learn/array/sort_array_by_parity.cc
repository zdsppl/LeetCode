//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3260/

//solution: time complexity:O(n)  space complexity:O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int size = A.size();
        int write_position = 0;
        int tmp = 0;
        if (size > 1) {
            for (int i = 0; i < size; ++i) {
                if (0 == (A[i] % 2)) {
                    if (write_position != i) {
                        tmp = A[write_position];
                        A[write_position] = A[i];
                        A[i] = tmp;
                    }
                    ++write_position;
                }
            }
        }
        return A;
    }
};
