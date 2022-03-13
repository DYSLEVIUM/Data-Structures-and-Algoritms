class Solution {
public:
    int maxProduct(vector<int>& nums) {
      priority_queue<int, vector<int>, greater<int>> min_heap;
      
      for(int& num: nums) {
        min_heap.push(num);
        if(min_heap.size() > 2) min_heap.pop();
      }
      
      int prod = 1;
      while(!min_heap.empty()){
        prod *= min_heap.top() - 1;
        min_heap.pop();
      }
      
      return prod;
    }
};
