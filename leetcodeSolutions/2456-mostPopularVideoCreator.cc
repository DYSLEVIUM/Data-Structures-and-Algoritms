class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        
        long long maxx = 0;
        unordered_map<string, long long> fa;
        unordered_map<string, int> vid_max;
        for(int i = 0; i < n; ++i) {
            fa[creators[i]] += views[i];
            vid_max[creators[i]] = vid_max.count(creators[i]) ? max(vid_max[creators[i]], views[i]) : views[i];
            maxx = max(maxx, fa[creators[i]]);
        }

        unordered_map<string, string> ans_mp;
        for(int i = 0; i < n; ++i) {
            if(fa[creators[i]] == maxx && views[i] == vid_max[creators[i]]) {
                if(ans_mp.count(creators[i])) ans_mp[creators[i]] = min(ans_mp[creators[i]], ids[i]);          
                else ans_mp[creators[i]] = ids[i];
            }
        }

        vector<vector<string>> ans;
        for(auto & [creator, id] : ans_mp) ans.push_back({creator, id});
        
        return ans;
    }
};
