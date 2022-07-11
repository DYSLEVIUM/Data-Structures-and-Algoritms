class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      int n = nums.size();
      
      int l_ptr = 0, r_ptr = 0;
      deque<int> min_queue, max_queue;
      while(r_ptr < n) {
        while(!max_queue.empty() && nums[max_queue.back()] < nums[r_ptr]) {
          max_queue.pop_back();
        }
        
        while(!min_queue.empty() && nums[min_queue.back()] > nums[r_ptr]) {
          min_queue.pop_back();
        }
        
        max_queue.push_back(r_ptr);
        min_queue.push_back(r_ptr);

        if(nums[max_queue.front()] - nums[min_queue.front()] > limit) {
          if(nums[max_queue.front()] == nums[l_ptr]) {
            max_queue.pop_front();
          }
          
          if(nums[min_queue.front()] == nums[l_ptr]) {
            min_queue.pop_front();
          }
          
          ++l_ptr;
        }
        
        ++r_ptr;
      }
      
      return r_ptr - l_ptr;
    }
};
