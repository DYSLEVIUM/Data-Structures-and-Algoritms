class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int cnt = (s[0] == 'L' ? -1 : 1);
        
        for(int i = 1;i < s.length(); ++i){
            if(s[i] == 'L') --cnt;
            else ++cnt;
            
            if (!cnt) ++ans;
        }
        
        return ans;
    }
};
