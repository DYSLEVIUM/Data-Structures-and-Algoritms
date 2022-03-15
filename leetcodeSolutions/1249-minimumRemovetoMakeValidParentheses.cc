class Solution {
public:
    string minRemoveToMakeValid(string s) {
      auto check = [](const string& x)->pair<string, int>{
        string new_string = "";
        int open = 0, closed = 0, removed = 0;
        for(char ch: x){
          if(ch == '(') ++open;
          else if(ch == ')'){
            if(open) --open;
            else{
              ++removed;
              continue;              
            }
          } 
          new_string += ch;
        }
        
        reverse(new_string.begin(), new_string.end());  //  so that the last open bracket comes to the first to erase
        while(open--){
          new_string.erase(new_string.find('('), 1);
          ++removed;
        }
        reverse(new_string.begin(), new_string.end());  //  bringing the string back to previous order

        return {new_string, removed};
      };
      pair<string, int> ans_1 = check(s); //  left to right
      
      auto rev = [](string &x){
        reverse(x.begin(), x.end());
        
        for(char& ch: x) 
          if(ch == '(') ch = ')';
          else if (ch == ')') ch = '(';
      };
      rev(s); //  a'

      pair<string, int> ans_2 = check(s); //  right to left
      rev(ans_2.first); //  (a')'
      
      if(ans_1.second < ans_2.second) return ans_1.first;
      return ans_2.first;
    }
};
