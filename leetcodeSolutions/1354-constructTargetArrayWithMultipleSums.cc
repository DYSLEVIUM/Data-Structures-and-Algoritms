class Solution {
public:
    bool isPossible(vector<int>& target) {
      auto sum = accumulate(target.begin(), target.end(), 0LL);
      priority_queue<int> max_heap(target.begin(), target.end());
      //  2 * max > sum
      while(sum > 1 && max_heap.top() > sum / 2) {
        int curr = max_heap.top();
        max_heap.pop();
        
        sum -= curr;
        if (sum <= 1) {
          return sum;
        }
        curr %= sum;
        max_heap.push(curr);
        sum += curr;
      }
      
      return sum == target.size();
    }
};
