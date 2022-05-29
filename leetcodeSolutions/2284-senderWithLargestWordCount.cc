class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        
        auto strcmp = [](const string &a, const string &b){
            int a_cnt = 0, b_cnt = 0;
            
            if(a == b) return 0;
            
            while(a_cnt < a.length() && b_cnt < b.length()) {
                if(a[a_cnt] < b[b_cnt]) return -1;
                else if(a[a_cnt] > b[b_cnt]) return 1;
                ++a_cnt, ++b_cnt;
            }
            
            if(a_cnt < b_cnt) return -1;
            
            return 1;
        };
        
        auto get_count = [](string s){
            while(s.back() == ' ') {
                s.pop_back();
            }
            
            reverse(s.begin(), s.end());
            while(s.back() == ' ') {
                s.pop_back();
            }

            reverse(s.begin(), s.end());

            int cnt = 0;
            for(int i = 0; i < s.length(); ++i) {
                cnt += s[i] == ' ';
            }
            
            return cnt + 1;
        };
        
        unordered_map<string, int> mp;
        for(int i = 0; i < n; ++i) {
            mp[senders[i]] += get_count(messages[i]);
        }
        
        string ans;
        int curr_cnt = INT_MIN;
        
        for(auto &[sender, cnt]: mp) {
            if(curr_cnt <= cnt) {
                if(curr_cnt == cnt) {
                    if(strcmp(sender, ans) >= 0) {
                        ans = sender;
                    }   
                } else {
                    ans = sender;
                    curr_cnt = cnt;    
                }
            }
        }
        
        return ans;
    }
};
