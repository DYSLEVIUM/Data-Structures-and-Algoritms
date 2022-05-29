class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int n = sentence.size();
        
        string ans = "";
        for(int i = 0; i < n; ++i) {
            if(sentence[i] == '$') {
                ans += '$';
                
                if(i - 1 >= 0 && sentence[i - 1] != ' ') {
                    continue;
                }
                
                int j = i + 1;
                long double num = 0;
                while(j < n && sentence[j] - '0' >= 0 && sentence[j] - '0' <= 9) {
                    num = num * 10 + (sentence[j] - '0');
                    ++j;
                }
                
                if(j < n && sentence[j] != ' ') {
                    continue;
                }
                
                if(i != j - 1) {
                    string new_str = to_string(num - (num * 1.0 * discount / 100));
                    string valid_str = "";
                    int k = 0;
                    while(new_str[k] != '.') {
                        valid_str += new_str[k++];
                    }
                    valid_str += new_str[k];
                    valid_str += new_str[k + 1];
                    valid_str += new_str[k + 2];
                    
                    ans += valid_str;
                }
                i = j - 1;
            } else {
                ans += sentence[i];
            }
        }
        
        return ans;
    }
};
