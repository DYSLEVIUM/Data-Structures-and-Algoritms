class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        
        unordered_set<int> allowed;
        for(auto &num : arr) {
            allowed.insert(num);
        }
        
        unordered_map<int, int> cache;
        auto recur = [&](const auto &recur, const int &node) -> int {
            if(cache.count(node)) {
                return cache[node];
            }
            
            long long curr_total = 1;
            for(auto &num : arr) {
                if(node % num == 0 && allowed.count(node / num)) {
                    curr_total += 1LL * recur(recur, node / num) * recur(recur, num);
                    curr_total %= MOD;
                }
            }
            
            return cache[node] = curr_total;
        };
        
        int total = 0;
        for(auto &num: arr) {
            total += recur(recur, num);
            total %= MOD;
        }
        
        return total;
    }
};
