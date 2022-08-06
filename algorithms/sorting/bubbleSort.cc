#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> nums{5, 1, 4, 2, 8};
  int n = nums.size();

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] > nums[j]) {
        swap(nums[i], nums[j]);
      }
    }
  }

  for (auto &num : nums) {
    cout << num << ' ';
  }
}
