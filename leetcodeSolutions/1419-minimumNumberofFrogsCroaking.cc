class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
      map<char, int> mp;
      mp['c'] = 0;
      mp['r'] = 0;
      mp['o'] = 0;
      mp['a'] = 0;
      mp['k'] = 0;

      int ans = INT_MIN;
      for(auto& letter: croakOfFrogs){
        ++mp[letter];
        
        ans = max(ans, mp['c']);
        
        bool all_atleast_one = true;
        
        for(auto& it:mp){
          if(it.second==0) all_atleast_one = false;
        }
        
        if(all_atleast_one){
          for(auto& it:mp)--it.second;
        }
        
        if(mp['c']>=mp['r'] && mp['r']>=mp['o'] && mp['o']>=mp['a'] && mp['a']>=mp['k']) continue;
        else return -1;
      }
      
      for(auto& it:mp){
        if(it.second!=0) return -1;
      }
      
      return ans;
    }
};
