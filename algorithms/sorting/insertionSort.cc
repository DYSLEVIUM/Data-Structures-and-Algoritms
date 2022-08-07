#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> nums{5, 1, 4, 2, 8};
  int n = nums.size();

  // in insertion sort, we divide the array into two parts, left side is sorted and the right side is unsorted, we take an element from the right side and place it at the correct position in the sorted list
  // sublist of size 1 is always sorted
  for (int i = 1; i < n; ++i) {
    int key = nums[i];
    int j = i - 1;

    while (j >= 0 && nums[j] > key) {
      // moving the elements to make room for the new element in the sorted list
      nums[j + 1] = nums[j];
      --j;
    }
    nums[j + 1] = key;
  }

  for (auto &num : nums) {
    cout << num << ' ';
  }
}
