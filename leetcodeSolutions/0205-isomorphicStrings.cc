class Solution {
public:
    bool isIsomorphic(string s, string t) {
//       if(s.length() != t.length()) return false;
      
//       int n = s.length();
//       unordered_map<char, char> encoded_s;
//       unordered_set<char> used_ch;
      
//       for(int i=0;i<n;++i){
//         if(encoded_s.find(s[i]) != encoded_s.end()){
//           if(encoded_s[s[i]] != t[i]) return false;
//         }else{
//           if(used_ch.find(t[i])!=used_ch.end()) return false;
//           encoded_s[s[i]] = t[i];
//           used_ch.insert(t[i]);
//         }
//       }
      
//       return true;
      
      auto normalize_string = [](string& a){
        unordered_map<char, char> mp;
        char ch_ptr = 'a';
        
        for(char& ch: a){
          if(!mp[ch]) mp[ch] = ch_ptr++;
        }
        
        for(int i = 0; i < a.length(); ++i) a[i] = mp[a[i]];
        
        return a;
      };
      
      return normalize_string(s) == normalize_string(t);
    }
};
