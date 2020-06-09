//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3245/

//solution1: time complexity: O(n2)  space complexity: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int size = arr.size();
        for (int i = 0; i < size; ++i) {
            if (0 == arr[i]) {
                for (int j = size - 1; j > i + 1; --j) {
                    arr[j] = arr[j - 1];
                }
                if (++i < size) {
                    arr[i] = 0;
                }
            }
        }
    }
};

//solution2: time complexity: O(n)  space complexity: O(n)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> v;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                v.push_back(0);
            }
            v.push_back(arr[i]);
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = v[i];
        }
    }
};
