class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        
        unordered_map<string, int> cnt;
        
        string res;
        int mx_cnt = 0;
        for(int i = 0; i < n; ++i) {
            int words = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            int total = cnt[senders[i]] += words;
            
            if(total > mx_cnt || (total == mx_cnt && senders[i] > res)) {
                mx_cnt = total;
                res = senders[i];
            }
        }
        
        return res;
    }
};
