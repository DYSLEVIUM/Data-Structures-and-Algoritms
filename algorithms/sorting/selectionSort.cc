#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> nums{5, 1, 4, 2, 8};
  int n = nums.size();

  // in selection sort, we divide the array into two subarrays, one is sorted
  // and the other is unsorted, in each iteration we pick the smallest element
  // from the unsorted subarray and place it at its correct position

  for (int i = 0; i < n - 1; ++i) {
    int minn_idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (nums[minn_idx] > nums[j]) {
        minn_idx = j;
      }
    }

    swap(nums[i], nums[minn_idx]);
  }

  for (auto &num : nums) {
    cout << num << ' ';
  }
}
