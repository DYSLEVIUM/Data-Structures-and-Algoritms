class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string,int> mp;
      
      for(auto x:words) ++mp[x];
      
      auto cmp = [](const pair<int,string> &a, const pair<int,string> &b){
        if(a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
      };
      
      priority_queue<
        pair<int,string>,
        vector<pair<int,string>>, 
        decltype(cmp)> minHeap(cmp);
      
      for(auto x: mp){
        minHeap.push({x.second,x.first});
        if(minHeap.size()>k) minHeap.pop();
      }
      
      vector<string> ans;
      
      while(!minHeap.empty()){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
      }
      
      reverse(ans.begin(),ans.end());
      
      return ans;
    }
};
