class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        //  using multiset as priority queue doesn't have erase
        multiset<int, greater<int>> max_heap;
        
        int i = 0;
        for(;i<k;++i) max_heap.insert(nums[i]);
        
        vector<int> ans;
        ans.push_back(*max_heap.begin());
        
        for(;i<n;++i){
            max_heap.erase(max_heap.find(nums[i-k]));
            max_heap.insert(nums[i]);
            ans.push_back(*max_heap.begin());
        }
        
        return ans;
    }
};
