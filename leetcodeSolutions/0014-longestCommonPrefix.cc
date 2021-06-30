class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        
        for(int i=1;i<strs.size();++i){
            for(int j=0;j<pre.length();++j){
                if(pre[j]!=strs[i][j]) pre.erase(j);
            }
        }
        
        return pre;
    }
};
