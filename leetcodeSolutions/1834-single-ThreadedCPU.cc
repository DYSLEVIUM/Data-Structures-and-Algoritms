class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
      int n = tasks.size();
      if(!n) return {};
      
      for(int i = 0; i < n; ++i) {
        tasks[i].push_back(i);
      }
      sort(tasks.begin(), tasks.end());
      
      using PI = pair<int, int>;
      
      vector<int> ans;
      long long idx = 0, curr_time = 0;
      priority_queue<PI, vector<PI>, greater<PI>> min_heap;
      while(idx < n || !min_heap.empty()) {
        if(min_heap.empty()) {
          curr_time = max(curr_time, 1LL * tasks[idx][0]);
        }
        //  add the backlogs
        while(idx < n && curr_time >= tasks[idx][0]) {
          min_heap.emplace(tasks[idx][1], tasks[idx][2]);
          ++idx;
        }
        auto [time, min_idx] = min_heap.top();
        min_heap.pop();
        curr_time += time;
        ans.push_back(min_idx);
      }
      
      return ans;
    }
};
