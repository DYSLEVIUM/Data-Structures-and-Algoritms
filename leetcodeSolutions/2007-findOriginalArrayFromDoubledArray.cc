class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
      int n = changed.size();
      if(n & 1) {
        return {};
      }
      
      vector<int> ans;
      multiset<int> se(changed.begin(), changed.end());
      while(!se.empty()) {
        int last = *se.rbegin();
        int conj = last / 2;

        // odd element is not possible at last
        if((last & 1) || se.count(conj)) {
          return {};
        }
        
        ans.push_back(conj);
        
        se.erase(se.find(last));
        se.erase(se.find(conj));
      }
      
      return ans;
    }
};
