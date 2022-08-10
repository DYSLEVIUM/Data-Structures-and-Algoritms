#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> nums{5, 1, 4, 2, 3};
  int n = nums.size();

  auto partition = [&](const int &lo, const int &hi) {
    // pivot should be first positon, last position, random or median, any one
    int pivot = nums[hi];
    int prev_large_pos = lo;

    for (int i = lo; i <= hi; ++i) {
      if (nums[i] <= pivot) {
        swap(nums[i], nums[prev_large_pos]);
        ++prev_large_pos;
      }
    }

    return prev_large_pos - 1;
  };

  auto quick_sort = [&](const auto &quick_sort, const int &lo,
                        const int &hi) -> void {
    if (lo >= hi) {
      return;
    }

    // getiing the partition point
    int parti = partition(lo, hi);

    quick_sort(quick_sort, lo, parti - 1);
    quick_sort(quick_sort, parti + 1, hi);
  };
  quick_sort(quick_sort, 0, n - 1);

  for (auto &num : nums) {
    cout << num << ' ';
  }
}
