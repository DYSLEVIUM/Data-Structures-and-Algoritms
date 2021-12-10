class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        const auto gen_paren = [&](const auto& gen_paren, string curr = "", int open = 0, int close = 0){
            if(curr.length() == 2 * n){
                ans.push_back(curr);
                return;
            }
            
            if(open < n) gen_paren(gen_paren, curr + "(", open + 1, close);
            
            if(close < open) gen_paren(gen_paren, curr + ")", open, close + 1);
        };
        
        gen_paren(gen_paren);
        
        return ans;
    }
};
