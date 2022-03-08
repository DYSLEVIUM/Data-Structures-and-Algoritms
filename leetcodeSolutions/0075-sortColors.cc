class Solution {
public:
    void sortColors(vector<int>& nums) {
//       vector<int> cnt(3);
//       for(int& num: nums) ++cnt[num];
      
//       int ptr = 0;
//       for(int i = 0; i < nums.size(); ++i) {
//         while(!cnt[ptr]) ++ptr;
//         nums[i] = ptr;
//         --cnt[ptr];
//       }
      
      //  using quick sort
      auto quick_sort = [&nums](const auto& quick_sort, const int& l, const int& r) -> void {
        auto partition = [&nums](const int& l, const int& r){
          int pivot = nums[r];
          int i = l - 1;

          for(int j = l; j < r; ++j){
            if(nums[j] < pivot) swap(nums[++i], nums[j]);
          }

          swap(nums[i + 1], nums[r]);
          return i + 1;  
        };
        
        if(l < r) {
          int parti = partition(l, r);
          quick_sort(quick_sort, l, parti - 1);
          quick_sort(quick_sort, parti + 1, r);
        }
      };
      
      quick_sort(quick_sort, 0, nums.size() - 1);
    }
};
