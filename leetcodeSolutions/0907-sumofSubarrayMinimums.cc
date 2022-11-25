class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        static constexpr int MOD = 1e9 + 7;
        int n = arr.size();

        stack<int> st;
        vector<int> nse(n); // next smaller element
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();
        vector<int> pse(n); // prev smaller element
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();

            st.push(i);
        }

        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            long long le = i - pse[i];
            long long ri = nse[i] - i;
            long long num = (le * ri) % MOD;
            sum += (num * arr[i]) % MOD;
            sum %= MOD;
        }

        return sum;
    }
};
