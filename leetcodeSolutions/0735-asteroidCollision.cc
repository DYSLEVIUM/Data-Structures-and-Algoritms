class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = asteroids.size();

        stack<int> st;
        for(const int & asteroid : asteroids) {
            st.push(asteroid);
            while(st.size() > 1) {
                int tp1 = st.top(); st.pop();
                int tp2 = st.top(); st.pop();

                if(tp1 * tp2 > 0 || tp1 > tp2) { // same sign or going opposite
                    st.push(tp2), st.push(tp1);
                    break;
                }

                if(!(tp1 + tp2)) {
                    continue;
                }
                
                abs(tp1) > abs(tp2) ? st.push(tp1) : st.push(tp2);
            }            
        }

        vector<int> ans;
        ans.reserve(st.size());
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
};
