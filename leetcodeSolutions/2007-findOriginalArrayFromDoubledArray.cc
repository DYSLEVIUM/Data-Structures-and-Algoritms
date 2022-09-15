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

        // odd element is not possible at last, and also if conjugate is not present
        if((last & 1) || se.find(last / 2) == se.end()) {
          return {};
        }
        
        ans.push_back(last / 2);
        
        se.erase(se.find(last));
        se.erase(se.find(last / 2));
      }
      
      return ans;
    }
};
