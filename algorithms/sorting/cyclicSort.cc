#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> nums{5, 1, 4, 2, 3};
  int n = nums.size();

  // cycle sort is valid if numbers are continuous
  for (int i = 0; i < n; ++i) {
    // each number is either in its correct position or, we make it at its
    // correct position
    if (nums[i] != i + 1) {
      swap(nums[i], nums[nums[i] - 1]);
    }
  }

  for (auto &num : nums) {
    cout << num << ' ';
  }
}
