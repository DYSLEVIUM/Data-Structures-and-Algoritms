class Solution {
public:
    bool strongPasswordCheckerII(string password) {
      if(password.length() < 8) return false;
      
      unordered_set<char> sp{ '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+' };
      bool has_upper = false, has_lower = false, has_special = false, has_digit = false;
      for(auto &ch: password) {
        if(ch >= 'A' && ch <= 'Z') {
          has_upper = true;
        } else if(ch >= 'a' && ch <= 'z') {
          has_lower = true;
        } else if(sp.find(ch) != sp.end()) {
          has_special = true;
        } else if(ch >= '0' && ch <= '9') {
          has_digit = true;
        } else {
          //  invalid character
          return false;
        }
      }
      
      for(int i = 1; i < password.size(); ++i) {
        if(password[i] == password[i - 1]) {
          return false;
        }
      }
      return has_upper && has_lower && has_special && has_digit;
    }
};
