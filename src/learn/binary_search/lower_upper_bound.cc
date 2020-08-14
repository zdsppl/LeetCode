#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//if target exist, return the index
//if target not exist, return -1
int binary_search(const vector<int> nums, const int target)
{
  int res_index = -1;
  int left = 0;
  int right = nums.size() - 1;
  int mid = 0;

  while (left <= right) {
    mid = left + (right - left) / 2;
    if (target == nums[mid]) {
      res_index = mid;
      break;
    } else if (target > nums[mid]) {
      left = mid + 1;
    } else if (target < nums[mid]) {
      right = mid - 1;
    }
  }

  return res_index;
}

//return first index, equal or more than target
//if all element > target, return 0
//if all element < target, return nums.size()
int lower_bound(const vector<int> nums, const int target)
{
  int res_index = 0;
  int left = 0;
  int right = nums.size() - 1;
  int mid = 0;

  if (nums[left] > target) {
    res_index = 0;
  } else if (nums[right] < target) {
    res_index = -1;
  } else {
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    res_index = left;
  }

  return left;
}

//return first index more than target
//if all element > target, 0
//if all element < target, return -1
int upper_bound(const vector<int> nums, const int target)
{
  int res_index = 0;
  int left = 0;
  int right = nums.size() - 1;
  int mid = 0;

  if (nums[left] > target) {
    res_index = 0;
  } else if (nums[right] < target) {
    res_index = -1;
  } else {
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    res_index = left;
  }

  return res_index;
}
int main()
{
  vector<int> test1({1,2,2,3,4,5,5,6});
  int lower = lower_bound(test1, 1);
  int upper = upper_bound(test1, 4);
  printf("lower = %d, upper = %d\n", lower, upper);

  return 0;
}
