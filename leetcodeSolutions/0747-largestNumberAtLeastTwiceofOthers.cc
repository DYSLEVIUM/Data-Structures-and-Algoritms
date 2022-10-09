class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(int i = 0; i < nums.size(); ++i) {
            min_heap.push({nums[i], i});
            if(min_heap.size() > 2) {
                min_heap.pop();
            }
        }

        auto ff = min_heap.top(); min_heap.pop();
        auto ss = min_heap.top(); min_heap.pop();

        return ss.first >= 2 * ff.first ? ss.second : -1;
    }
};
