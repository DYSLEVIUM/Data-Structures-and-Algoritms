class Solution {
public:
    int removePalindromeSub(string s) {
      bool is_palindrome = true;
      for(int i = 0; i < s.length(); ++i) is_palindrome &= s[i] == s[s.length() - i - 1];
      
      return is_palindrome ? 1 : 2;
    }
};
