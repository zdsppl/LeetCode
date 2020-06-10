//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3157/

//solution1: time complexity:O(N2)  space complexity:O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if (size > 1) {
            for (int i = 0; i < size; ++i) {
                if (0 == nums[i]) {
                    for (int j = i + 1; j < size; ++j) {
                        if (0 != nums[j]) {
                            nums[i] = nums[j];
                            nums[j] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
};

//solution2: time complexity:O(n)  space complexity:O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[idx] = nums[i];
                ++idx;
            }
        }
        
        for (; idx < nums.size(); ++idx) {
            nums[idx] = 0;
        }
        
    }
};

//solutions: time complexity:O(n)  space complexity:O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
		//use temp to save nums[i], for the case i == k
                int temp = nums[i];
                nums[i] = 0;
                nums[k] = temp;
                k++;
            }
        }
    }
};
