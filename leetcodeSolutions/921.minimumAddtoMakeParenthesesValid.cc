class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        
        int ans = 0;
        
        for(auto x:s){
            if(x=='(') st.push('(');
            else {
                if(!st.empty() && st.top()=='(') st.pop();
                else ++ans; //  we add a bracket any time we it becomes invalid
            }
        }
        
        ans+=st.size(); //  for multiple ( 
        
        return ans;
    }
};
