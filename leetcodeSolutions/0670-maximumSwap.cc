#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num);
        const int n = num_str.size();

        vector<int> next_greater(n, -1);

        stack<int> st;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && num_str[st.top()] < num_str[i]) {
                st.pop();
            }

            if(!st.empty()) {
                next_greater[i] = st.top();
                if(num_str[i] <= num_str[st.top()]) {
                    continue;
                }
            }
            st.push(i);
        }

        int maxx = num;
        for(int i = 0; i < n; ++i) {
            if(next_greater[i] == -1) {
                continue;
            }

            swap(num_str[i], num_str[next_greater[i]]);
            maxx = max(maxx, stoi(num_str));
            swap(num_str[i], num_str[next_greater[i]]); // backtrack, as only max one swap is allowed
        }

        return maxx;
    }
};
