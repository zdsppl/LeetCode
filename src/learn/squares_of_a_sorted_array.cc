//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/

//solution1: time complexity: O(n*LGn); space complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
       vector<int> square_vector;
        for (int i = 0; i < A.size(); ++i) {
            square_vector.push_back(std::pow(A[i], 2));
        }
        std::sort(square_vector.begin(), square_vector.end());
        return square_vector;
    }
};

//solution2: time complexity: O(n); space complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> sorted_squares(A.size());
        int left = 0;
        int right = A.size() - 1;
        int temp_left_square = 0;
        int temp_right_square = 0;
        int current_sorted_square_index = A.size() - 1;
        while (left <= right) {
            temp_left_square = std::pow(A[left], 2);
            temp_right_square = std::pow(A[right], 2);
            if (temp_left_square > temp_right_square) {
                sorted_squares[current_sorted_square_index--] = temp_left_square;
                ++left;
            } else {
                sorted_squares[current_sorted_square_index--] = temp_right_square;
                --right;
            }
        }
        return sorted_squares;
    }
};
