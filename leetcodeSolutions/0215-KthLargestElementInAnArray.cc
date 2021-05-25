class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int,vector<int>, greater<int>> mxHeap;
      
      for(auto x: nums){
        mxHeap.push(x);
        if(mxHeap.size()>k) mxHeap.pop();
      }
      
      return mxHeap.top();
    }
};
