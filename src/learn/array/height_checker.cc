//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3228/

//solution: time complexity:O(Nlgn)   space complexity:O(n)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted_heights = heights;
        std::sort(sorted_heights.begin(), sorted_heights.end());
        int moved_number = 0;
        for (int i = 0; i < sorted_heights.size(); ++i) {
            if (heights[i] != sorted_heights[i]) {
                ++moved_number;
            }
        }
        return moved_number;
    }
};
