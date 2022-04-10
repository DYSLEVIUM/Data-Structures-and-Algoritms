class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        
        for(int& num: nums) {
          min_heap.push(num);
        }
        
        while(k--) {
            int x = min_heap.top();
            min_heap.pop();
            ++x;
            min_heap.push(x);
        }
         
        int ans = 1;
        constexpr int MOD = 1e9 + 7;
        while(!min_heap.empty()){
            ans = ((ans % MOD) * (min_heap.top() % MOD)) % MOD;
            min_heap.pop();
        }
        
        return ans;
    }
};
