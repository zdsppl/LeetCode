//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3237/

//solution1:
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        int num = 0;
        const int ten_1 = 10;
        const int ten_2 = 100;
        const int ten_3 = 1000;
        const int ten_4 = 10000;
        const int ten_5 = 100000;
        for (int i = 0; i < nums.size(); ++i) {
            num = nums.at(i);
            if (num >= ten_3) {
                if (num >= ten_3 && num < ten_4) {
                    ++result;
                } else if (ten_5 == num) {
                    ++result;
                }
            } else {
                if (num < ten_2 && num >= ten_1) {
                    ++result;
                }
            }
        }
        return result;
    }
};

//solution2: common
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int result = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int tmp_counter = 0;
            
            for (; nums[i] > 0; nums[i] /= 10)
            {
                tmp_counter++;
            }
            
            if(tmp_counter %2 == 0)
            {
                result++;
            }
        }
        return result;
    }
};

//solution3: fast
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]<=9999&&nums[i]>=1000)||(nums[i]<=99&&nums[i]>=10))ans++;
        }
        return ans;
    }
}

