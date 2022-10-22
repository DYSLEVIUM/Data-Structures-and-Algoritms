class Solution {
public:
    string minWindow(const string & s, const string & t) {
        int s_n = s.size();

        unordered_map<char, int> tar; // to check the total occurence of a character
        for(auto & ch : t) ++tar[ch];

        unordered_map<char, int> fa; // frequency of target characters in a particular window

        int cnt = 0, dis = tar.size(); // cnt represents total distinct characters that we have found, dis represents the total distinct characters in t
        pair<int, int> ans{-1, INT_MAX}; // starting point and length
        for(int l = 0, r = -1; l < s_n && r < s_n; ++l) {
            if(!tar.count(s[l])) continue;
            
            if(l > r) {
                ++fa[s[l]]; // found start of range
                cnt = fa[s[l]] == tar[s[l]];
            }

            r = max(r, l); // it may be the case, that l moves ahead of r
            while(r + 1 < s_n && cnt != dis) { 
                char last = s[r + 1];
                if(tar.count(last)) {
                    ++fa[last]; // another one
                    if(fa[last] == tar[last]) ++cnt; // if after adding, we got all total occurence
                }
                ++r;
            }

            if(cnt == dis) {
                int curr_len = r - l + 1;
                if(ans.second > curr_len) ans = {l, curr_len};
            }

            // removing the first from the range for next iteration
            char first = s[l];
            if(fa[first] == tar[first]) --cnt; // if after removing, we don't have enough, we decrease cnt
            --fa[first];
        }

        return ans.first == -1 ? "" : s.substr(ans.first, ans.second);
    }
};
