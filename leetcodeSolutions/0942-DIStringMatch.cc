class Solution {
public:
    vector<int> diStringMatch(string s) {
        int minN = 0;
        int maxN = s.length();

        vector<int> ans;
        
        if(s[0]=='I') ans.push_back(minN++);
        else ans.push_back(maxN--);
        
        for(int i=1;i<s.length();++i){
            if(s[i]=='I') ans.push_back(minN++);
            else ans.push_back(maxN--);
        }
        
        ans.push_back(maxN);
            
        return ans;
    }
};
