class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = arr.size();

        int ans = arr[0], cnt = 0;
        #pragma unroll
        for(int i = 1; i < n && cnt != k; ++i) {
            if(ans > arr[i]) {
                ++cnt;
            } else {
                ans = arr[i];
                cnt = 1;
            }
        }

        return ans;
    }
};
