class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int p = 0;
        for(int i = 0; i < n; ++i) {
            int j = i + 1;
            while(j < n && chars[i] == chars[j]) {
                ++j;
            }
            --j;

            chars[p++] = chars[i];

            if(j - i + 1 != 1) {
                string num = to_string(j - i + 1);
                for(int k = 0; k < num.size(); ++k) {
                    chars[p++] = num[k];
                }
            }

            i = j;
        }

        return p;
    }
};

// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         int n = chars.size();
        
//         string ans;
//         for(int i = 0; i < n; ++i) {
//             int j = i + 1;
//             while(j < n && chars[i] == chars[j]) {
//                 ++j;
//             }
//             --j;

//             ans += chars[i];
//             if(j - i + 1 != 1) {
//                 ans += to_string(j - i + 1);
//             }

//             i = j;
//         }

//         int ans_n = ans.size();
//         for(int i = 0; i < ans_n; ++i) {
//             chars[i] = ans[i];
//         }

//         return ans_n;
//     }
// };
