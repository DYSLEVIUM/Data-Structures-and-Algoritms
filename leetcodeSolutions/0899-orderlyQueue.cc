class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans = s;
        // only rotation is possible in case of k == 1, but for k > 1, we can simply think of it as a consequent of bubble sort
        if(k == 1) {
            for(int i = 0; i < s.size(); ++i) {
                string temp = s.substr(i) + s.substr(0, i);
                if(temp < ans) ans = temp;
            }
        } else sort(ans.begin(), ans.end());
        
        return ans;
    }
};
