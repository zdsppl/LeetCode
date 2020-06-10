//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3231/

//solution1: time complexity:O(Nlgn)   space complexity:O(1);
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int third_maximum_number = 0;
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        if (1 == size) {
            third_maximum_number = nums[0];
        } else if (size < 3) {
            third_maximum_number = nums[size - 1];
        } else {
	    //for the case: [1, 2, 2, 3]
            third_maximum_number = nums[size - 1];
            int disct_count = 1;
            for (int i = size - 2; i >= 0; --i) {
                if (nums[i] != nums[i + 1]) {
                    ++disct_count;
                    if (3 == disct_count) {
                        third_maximum_number = nums[i];
                        break;
                    }
                }
            }
        }
        return third_maximum_number;
    }
};

//solution2: time complexity:O(n)  space complexity:O(1)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max = LONG_MIN;
        long second_max = LONG_MIN;
        long third_max = LONG_MIN;
        
        for(int i=0 ; i<nums.size() ; i++){
  
            if(nums[i]==max || nums[i]==second_max || nums[i]==third_max){
                continue;
            }
            
            if(nums[i]>max){
                third_max = second_max;
                second_max = max;
                max = nums[i];
            }else if(nums[i]>second_max){
                third_max = second_max;
                second_max = nums[i];
            }else if(nums[i]>third_max){
                third_max = nums[i];
            }
        }
        
        if(third_max==LONG_MIN){
            return max;
        }
        return third_max;

    }
};
