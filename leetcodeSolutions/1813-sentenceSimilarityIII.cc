#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool areSentencesSimilar(string & sentence1, string & sentence2) {
        auto cnt_words = [](const string & s){
            string word;
            stringstream ss(s);

            int cnt = 0;
            while(ss >> word) {
                ++cnt;
            }

            return cnt;
        };
        
        int n1 = cnt_words(sentence1), n2 = cnt_words(sentence2);
        if(n2 < n1) {
            swap(n1, n2), swap(sentence1, sentence2);
        }

        string word1, word2;

        stringstream ss1(sentence1), ss2(sentence2);
        ss1 >> word1;
        ss2 >> word2;

        int pre = 0;
        while(pre < n1) {
            if(word1 != word2) {
                break;
            }

            ++pre; // prefix matches
            ss1 >> word1;
            ss2 >> word2;

            if(pre == n1) {
                return true;
            }
        }

        ss1.str(""), ss2.str("");
        ss1.clear(), ss2.clear();

        reverse(sentence1.begin(), sentence1.end());
        ss1 << sentence1;

        reverse(sentence2.begin(), sentence2.end());
        ss2 << sentence2;

        ss1 >> word1;
        ss2 >> word2;

        int suff = 0;
        while(suff < n1) {
            if(word1 != word2) {
                break;
            }

            ++suff; // suffix matches
            ss1 >> word1;
            ss2 >> word2;

            if(suff == n1) {
                return true;
            }
        }

        return pre + suff >= n1; // middle insertions
    }
};
