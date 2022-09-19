class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      unordered_map<string, function<long long (const long long &, const long long &)>> mp = {
        { "+", [] (const long long &a, const long long &b) { return a + b; }},
        { "-", [] (const long long &a, const long long &b) { return a - b; }},
        { "*", [] (const long long &a, const long long &b) { return a * b; }},
        { "/", [] (const long long &a, const long long &b) { return a / b; }}
      };
      
      stack<long long> st;
      for(auto &token : tokens) {
        if(!mp.count(token)) {
          st.push(stoi(token));
        } else {
          long long op1 = st.top();
          st.pop();
          
          long long op2 = st.top();
          st.pop();
          
          st.push(mp[token](op2, op1));
        }
      }
      
      return st.top();
    }
};
