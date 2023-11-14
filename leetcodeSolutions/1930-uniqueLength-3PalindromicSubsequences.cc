// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         constinit static int CHAR_SET = 26;

//         int n = s.size();

//         vector<vector<int>> pre(n, vector<int>(CHAR_SET));
//         ++pre[0][s[0] - 'a'];
//         for(int i = 1; i < n; ++i) {
//             pre[i] = pre[i - 1];
//             ++pre[i][s[i] - 'a'];
//         }

//         vector<vector<int>> suf(n, vector<int>(CHAR_SET));
//         ++suf[n - 1][s[n - 1] - 'a'];
//         for(int i = n - 2; i >= 0; --i) {
//             suf[i] = suf[i + 1];
//             ++suf[i][s[i] - 'a'];
//         }

//         unordered_set<string> se;
//         for(int i = 0; i < n; ++i) {
//             for(int j = 0; j < CHAR_SET; ++j) {
//                 if(i - 1 >= 0 && pre[i - 1][j] && 
//                     i + 1 < n && suf[i + 1][j]
//                 ) {
//                     string curr = "";
//                     curr += char(j + 'a');
//                     curr += s[i];
//                     curr += char(j + 'a');

//                     se.insert(curr);
//                 }
//             }
//         }
    
//         return se.size();
//     }
// };

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        constinit static int CHAR_SET = 26;

        vector<int> first(CHAR_SET, -1), last(CHAR_SET, -1);
        for(int i = 0; const char & c: s) {
            int curr = c - 'a';

            if(first[curr] == -1) {
                first[curr] = i;
            }

            last[curr] = i;

            ++i;
        }

        int ans = 0;
        for(int i = 0; i < CHAR_SET; ++i) {
            if(first[i] == -1) {
                continue;
            }

            unordered_set<char> between;
            for(int j = first[i] + 1; j < last[i]; ++j) {
                between.insert(s[j]);
            }

            ans += between.size();
        }

        return ans;
    }
};
