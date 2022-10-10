class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for(auto &cpdomain : cpdomains) {
            int cnt = 0;
            string curr;
            for(auto &ch : cpdomain) {
                if(ch == ' ') {
                    cnt = stoi(curr);
                    curr = "";
                } else {
                    curr += ch;
                }
            }
            reverse(curr.begin(), curr.end());

            string other;
            for(int i = 0; i <= curr.size(); ++i) {
                if(i == curr.size() || curr[i] == '.') {
                    mp[string(other.rbegin(), other.rend())] += cnt;
                    if(i == curr.size()) {
                        break;
                    }
                }
                other += curr[i];
            }
        }

        vector<string> ans;
        for(auto &[str, cnt] : mp) {
            ans.push_back(to_string(cnt) + ' ' + str);
        }

        return ans;
    }
};
