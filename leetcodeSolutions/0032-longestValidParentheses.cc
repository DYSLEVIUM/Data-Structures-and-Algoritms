class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        if(!n) return 0;
        
        vector<int> longest_valid_paren(n);
        for(int i = 1; i < n; ++i) {
            //  if curr char is ')' and the previous of longest valid parentheses is '(', we can increase the current size
            if(s[i] == ')' && (i - longest_valid_paren[i - 1] - 1 >= 0) &&s[i - longest_valid_paren[i - 1] - 1] == '(') {
                //  adding the current state brackets
                longest_valid_paren[i] = longest_valid_paren[i - 1] + 2;
                
                //  the longest substring present before, if it is valid of course
                if(i - longest_valid_paren[i - 1] - 2 >= 0) {                  
                    longest_valid_paren[i] += longest_valid_paren[i - longest_valid_paren[i - 1] - 2];
                }
            }
        }
        
        return *max_element(longest_valid_paren.begin(), longest_valid_paren.end());
    }
};
