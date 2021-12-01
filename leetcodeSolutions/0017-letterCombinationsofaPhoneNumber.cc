class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> map(10);
        
        map[2]=vector<string>({"a","b","c"});
        map[3]=vector<string>({"d","e","f"});
        map[4]=vector<string>({"g","h","i"});
        map[5]=vector<string>({"j","k","l"});
        map[6]=vector<string>({"m","n","o"});
        map[7]=vector<string>({"p","q","r","s"});
        map[8]=vector<string>({"t","u","v"});
        map[9]=vector<string>({"w","x","y","z"});
        
        vector<string> ans;
        
        for(int i=0;i<digits.size();++i){
            if(i==0){
                for(int j=0;j<map[digits[i]-'0'].size();++j) ans.push_back(map[digits[i]-'0'][j]);
                continue;
            }
            
            vector<string> temp;
            
            for(int k=0;k<ans.size();++k){
                for(int j=0;j<map[digits[i]-'0'].size();++j) temp.push_back(ans[k]+map[digits[i]-'0'][j]);
            }
            
            ans = temp;
        }
        
        return ans;
    }
};
