class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend_se;
        for(string &deadend: deadends) {
            deadend_se.insert(deadend);
        }
        
        int cnt = 0;
        queue<string> qu;
        qu.push("0000");
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                string fr = qu.front();
                qu.pop();
                
                if(deadend_se.find(fr) != deadend_se.end()) {
                    continue;
                }
                
                if(fr == target) {
                    return cnt;
                }
                
                deadend_se.insert(fr);
                
                string next_pattern = fr;
                for(int i = 0; i < 4; ++i) {
                    int num = (next_pattern[i] - '0');
                    
                    next_pattern[i] = char(((num + 1) % 10) + '0');
                    qu.push(next_pattern);
                    
                    next_pattern[i] = char(((num - 1 + 10) % 10) + '0');
                    qu.push(next_pattern);
                    
                    next_pattern = fr;
                }
            }
            ++cnt;
        }
        
        return -1;
    }
};
