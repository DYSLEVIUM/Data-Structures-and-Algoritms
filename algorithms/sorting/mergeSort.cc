#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> nums{5, 1, 4, 2, 3};
  int n = nums.size();

  auto merge = [&](const int &lo, const int &mid, const int &hi) {
    vector<int> temp(hi - lo + 1);
    int t_ptr = 0;

    int ptr_1 = lo, ptr_2 = mid + 1;
    while (ptr_1 <= mid && ptr_2 <= hi) {
      int minn;
      if (nums[ptr_1] < nums[ptr_2]) {
        minn = nums[ptr_1++];
      } else {
        minn = nums[ptr_2++];
      }
      temp[t_ptr++] = minn;
    }

    while (ptr_1 <= mid) {
      temp[t_ptr++] = nums[ptr_1++];
    }

    while (ptr_2 <= hi) {
      temp[t_ptr++] = nums[ptr_2++];
    }

    t_ptr = 0;
    for (int i = lo; i <= hi; ++i, ++t_ptr) {
      nums[i] = temp[t_ptr];
    }
  };

  auto merge_sort = [&](const auto &merge_sort, const int &lo,
                        const int &hi) -> void {
    if (lo >= hi) {
      return;
    }

    int mid = lo + ((hi - lo) >> 1);

    merge_sort(merge_sort, lo, mid);
    merge_sort(merge_sort, mid + 1, hi);

    merge(lo, mid, hi);
  };
  merge_sort(merge_sort, 0, n - 1);

  for (auto &num : nums) {
    cout << num << ' ';
  }
}
