class Solution {
public:
    bool halvesAreAlike(string s) {
        auto cnt_vowels = [](const string &x){
            int cnt = 0;
            for(auto& ch: x) cnt += (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u');
            
            return cnt;
        };
        
        int n = s.length();
        transform(s.begin(), s.end(), s.begin(), [](const char& c){ return tolower(c); });
        
        return cnt_vowels(string(s.begin(), s.begin() + n / 2)) == cnt_vowels(string(s.begin() + n / 2, s.end()));
    }
};
