class Solution {
public:
    int minSetSize(vector<int>& arr) {
      int n = arr.size();
      
      unordered_map<int, int> fa;
      for(auto &num : arr) {
        ++fa[num];  
      }
      
      priority_queue<int> max_heap;
      for(auto &[num, cnt] : fa) {
        max_heap.push(cnt);
      }
      
      int ans = 0;
      int curr_size = n;
      while(curr_size > n / 2) {
        int curr_cnt = max_heap.top();
        max_heap.pop();
        
        curr_size -= curr_cnt;
        ++ans;
      }
      
      return ans;
    }
};
