class Solution {
public:
    bool validPalindrome(string s) {
        int ptr_1 = 0, ptr_2 = s.length() - 1;
        
        auto is_palindrome = [](const string &x){
            int n = x.length();
            for(int i = 0; i < n; ++i) {
                if(x[i] != x[n - i - 1]) return false;
            }
            
            return true;
        };
        
        while(ptr_1 <= ptr_2) {
            if(s[ptr_1] == s[ptr_2]) ++ptr_1, --ptr_2;
            else {
                string le = "", ri = "";
                
                for(int i = ptr_1; i < ptr_2; ++i) le += s[i];
                for(int i = ptr_1 + 1; i <= ptr_2; ++i) ri += s[i];

                return is_palindrome(le) || is_palindrome(ri);
            }
        }
        
        return true;
    }
};
