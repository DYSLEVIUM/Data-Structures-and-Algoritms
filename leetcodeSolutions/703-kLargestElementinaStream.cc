class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int k;
    
    KthLargest(int k, vector<int>& nums):k(k) {
      for(auto x:nums){
        this->minHeap.push(x);
        if(this->minHeap.size()>k) this->minHeap.pop();
      }
    }
    
    int add(int val) {
      this->minHeap.push(val);
      if(this->minHeap.size()>k) this->minHeap.pop();
      return this->minHeap.top();
    }
};
