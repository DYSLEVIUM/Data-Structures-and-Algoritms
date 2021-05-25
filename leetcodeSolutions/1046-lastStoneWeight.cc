class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> maxHeap;
      
      for(auto x:stones) maxHeap.push(x);
      
      
      while(maxHeap.size()>1){
        int one = maxHeap.top();
        maxHeap.pop();
        
        int two = maxHeap.top();
        maxHeap.pop();
        
        if(one!=two) maxHeap.push(abs(one-two));
      }
      
      return maxHeap.size()==1?maxHeap.top():0;
    }
};
