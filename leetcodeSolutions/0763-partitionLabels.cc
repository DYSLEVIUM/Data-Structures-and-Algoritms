class Solution {
public:
    vector<int> partitionLabels(string s) {
        int fa[26];  // maxi
        
        for(int i=0;i<26;++i) fa[i] = INT_MIN;
        
        for(int i=0;i<s.length();++i) fa[s[i]-'a'] = max(i, fa[s[i]-'a']);
        
        vector<int> ans;
        
        int currDist=INT_MIN;
        int taken=0;
        for(int i=0;i<s.length();++i){
            currDist = max(currDist, fa[s[i]-'a']);
            ++taken;
            if(currDist==i){
                currDist=INT_MIN;
                ans.push_back(taken);
                taken=0;
            }
        }
        
        return ans;
    }
};
