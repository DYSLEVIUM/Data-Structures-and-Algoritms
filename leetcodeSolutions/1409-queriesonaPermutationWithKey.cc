class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
      list<int> permutation(m);
      iota(permutation.begin(), permutation.end(), 1);
      
      vector<int> ans;

      for(auto& query: queries){
        int iter = 0;
        for(auto& num: permutation){
          if(num==query) {
            ans.push_back(iter);
            break;
          }else ++iter;
        }
        permutation.remove(query);
        permutation.push_front(query);
      }
      
      return ans;
    }
};
