#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> nums{5, 1, 4, 2, 8};
  int n = nums.size();

  // for (int i = 0; i < n; ++i) {
  //   for (int j = i + 1; j < n; ++j) {
  //     if (nums[i] > nums[j]) {
  //       swap(nums[i], nums[j]);
  //     }
  //   }
  // }

  // bubble sort with early stopping
  bool swapped;
  for (int i = 0; i < n - 1; ++i) {
    swapped = false;
    for (int j = 0; j < n - 1 - i; ++j) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }

  for (auto &num : nums) {
    cout << num << ' ';
  }
}
