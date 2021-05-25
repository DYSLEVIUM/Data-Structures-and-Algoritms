class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int,int> mp;
      
      for(auto x: nums) ++mp[x];
      
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
      
      for(auto x: mp){
        minHeap.push({x.second,x.first});
        
        if(minHeap.size()>k) minHeap.pop();
      }
      
      vector<int> ans;
      
      while(!minHeap.empty()){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
      }
        
      return ans;
    }
};
