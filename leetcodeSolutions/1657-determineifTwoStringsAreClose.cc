class Solution {
public:
    bool closeStrings(string word1, string word2) {
      vector<int> fa1(26), fa2(26);

      for(auto& letter: word1) ++fa1[letter-'a'];
      for(auto& letter: word2) ++fa2[letter-'a'];
      
      for(int i=0;i<26;++i){
        if(!fa1[i] && !fa2[i]) continue;  //  if both zero
        if(fa1[i] && fa2[i]) continue;  //  if both are non-zero
        else return false;
      }
      
      unordered_multiset<int> se;
      
      for(int i=0;i<26;++i) if(fa1[i]) se.insert(fa1[i]);
      
      for(int i=0;i<26;++i){
        if(fa2[i]){
          auto find_iter = se.find(fa2[i]);
          if(find_iter==se.end()) return false;
          else se.erase(find_iter);
        }
      }
      return true;
    }
};
