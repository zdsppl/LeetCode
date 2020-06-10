//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/

//solution: time complexity:O(n)  space complexity:O(1)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        int tmp_value = -1;
        int max_value = -1;
        if (size > 1) {
            max_value = arr[size - 1];
            for (int i = size - 2; i >= 0; --i) {
		//need save the prev value of arr[i] for update max_value
                tmp_value = arr[i];
                arr[i] = max_value;
                if (tmp_value > max_value) {
                    max_value = tmp_value;
                }
            }
        }
	//case:[400]
        if (size > 0) {
            arr[size - 1] = -1;
        }
        return arr;
    }
};
