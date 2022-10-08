class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> ans = prices;
        stack<int> st;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            ans[i] -= st.empty() ? 0 : st.top();
            st.push(prices[i]);
        }

        return ans;
    }
};

class Solution1 {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> ans = prices;
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
