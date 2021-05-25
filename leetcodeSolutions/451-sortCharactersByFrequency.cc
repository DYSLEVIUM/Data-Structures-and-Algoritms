class Solution {
public:
//     string frequencySort(string s) {
//       map<char,int> mp;
      
//       for(auto x: s) ++mp[x];
      
//       sort(s.begin(),s.end(),[&mp](char a,char b){
//         if(mp[a]==mp[b]) return b>a;
//         return mp[a]>mp[b];
//       });
      
//       return s;
//     }
  
    string frequencySort(string s) {
      map<char,int> mp;
      priority_queue<pair<int,char>> maxHeap;
      
      for(auto x: s) ++mp[x];
      
      for(auto x: mp) maxHeap.push({x.second,x.first});
      
      string newStr;
      
      while(!maxHeap.empty()){
        for(int i=0;i<maxHeap.top().first;++i) newStr+=maxHeap.top().second;
        maxHeap.pop();
      }
      
      return newStr;
    }
};
