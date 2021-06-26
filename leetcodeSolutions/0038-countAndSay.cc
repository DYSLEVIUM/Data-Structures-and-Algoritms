class Solution {
public:
    
    string countAndSay(int n) {
        if(n==1) return "1";

        auto say = [](string x, auto&& say){
            int cnt = 1;
            char reqChar = x[0];

            int i = 0;
            for (; i < x.length() - 1; ++i) {
              if (x[i + 1] == reqChar)
                ++cnt;
              else
                break;
            }
            ++i;

            string newStr = "";

            for (; i < x.length(); ++i) newStr += x[i];

            string ans = "";

            if (newStr == "") {
              ans += to_string(cnt) + reqChar;
              return ans;
            } else {
              ans += to_string(cnt) + reqChar + say(newStr, say);
            }

            return ans;
        };
        
        return say(countAndSay(n-1),say);
    }
};
