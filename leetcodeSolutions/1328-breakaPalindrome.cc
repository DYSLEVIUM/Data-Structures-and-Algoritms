class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) {
            return "";
        }

        bool is_changed = false;
        for(int i = 0; i < n / 2; ++i) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                is_changed = true;
                break;
            }
        }

        if(!is_changed) {
            palindrome[n - 1] = 'b';
        }

        return palindrome;
    }
};
