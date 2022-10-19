class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string_view, int> mp;
        for(const string &word: words) ++mp[word];

        using PSVI = pair<string_view, int>;
        auto cmp = [](const PSVI &lhs, const PSVI &rhs){
            if(lhs.second == rhs.second) return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        };

        priority_queue<PSVI, vector<PSVI>, decltype(cmp)> min_heap(cmp);
        for(const auto &[word, cnt] : mp) {
            min_heap.push({word, cnt});
            if(min_heap.size() > k) min_heap.pop();
        }

        vector<string> ans;
        while(!min_heap.empty()) {
            ans.push_back(static_cast<string>(min_heap.top().first));
            min_heap.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
