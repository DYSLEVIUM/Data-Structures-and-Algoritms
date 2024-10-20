#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool parseBoolExpr(string expression) {
        auto parse_or = [](const vector<int> & arr){
            return accumulate(arr.begin(), arr.end(), 0, bit_or());
        };

        auto parse_and = [](const vector<int> & arr){
            return accumulate(arr.begin(), arr.end(), 1, bit_and());
        };

        auto parse_not = [](const vector<int> & arr){
            assert(arr.size() == 1);
            return !arr[0];
        };

        stack<char> st;
        for(char & ch: expression) {
            if(ch != ')') {
                st.push(ch);
                continue;
            }
            
            string lis;
            while(st.top() != '(') {
                lis += st.top();
                st.pop();
            }
            st.pop();

            vector<int> vals;
            vals.reserve((lis.size() >> 1) + 1);

            stringstream ss(lis);
            string lit;
            while(getline(ss, lit, ',')) {
                vals.push_back(lit[0] == 't');
            }

            int val;
            char op = st.top();
            switch(op) {
                case '|':
                    val = parse_or(vals);
                    break;
                case '&':
                    val = parse_and(vals);
                    break;
                case '!':
                    val = parse_not(vals);
                    break;
            }

            st.push(val ? 't' : 'f');
        }

        return st.top() == 't';
    }
};
