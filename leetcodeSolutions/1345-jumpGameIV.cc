class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
        }
        
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(0);
        int cnt = 0;
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                int fr = qu.front();
                qu.pop();
                
                if(fr < 0 || fr >= n || visited.find(fr) != visited.end()) {
                    continue;
                }
                
                if(fr == n - 1){
                    return cnt;
                }
                
                visited.insert(fr);
                qu.push(fr + 1);
                qu.push(fr - 1);
                for(auto &idx: mp[arr[fr]]) {
                    if(visited.find(idx) != visited.end()){
                        continue;
                    }
                    qu.push(idx);
                }
                mp[arr[fr]] = {};   //  mp[arr[fr]].clear() gives TLE
            }
            ++cnt;
        }
        return -1;
    }
};
