class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        static constexpr int CHAR_SET = 26;

        vector<int> fa1(CHAR_SET);
        for(char &ch : s1) ++fa1[ch - 'a'];

        int len = s1.size();
        if(len > s2.size()) return false;

        vector<int> fa2(CHAR_SET);
        for(int i  = 0; i < len - 1; ++i) ++fa2[s2[i] - 'a'];
        
        for(int i = len - 1; i < s2.size(); ++i) {
            ++fa2[s2[i] - 'a'];
            bool all_same = true;
            for(int j = 0; j < CHAR_SET; ++j) all_same &= fa1[j] == fa2[j];
            if(all_same) return true;
            --fa2[s2[i - len + 1] - 'a'];
        }

        return false;
    }
};
