#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        static const int INF = 0x3f3f3f3f;

        const int n = nums.size();

        stack<int> st;
        for(int i = 0; i < n; ++i) {
            if(!st.empty() && nums[i] > nums[st.top()]) {
                continue;
            }
            st.push(i);
        }

        int maxx = -INF;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                maxx = max(maxx, i - st.top());
                st.pop();
            }
        }

        return maxx;
    }
};
