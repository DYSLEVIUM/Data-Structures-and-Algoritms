class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto get_new_str = [](const string &str){
            string new_str = "";
            for(auto &ch: str) {
                if(ch == '#') {
                    if(new_str.length()) new_str.pop_back();
                    continue;
                }
                new_str += ch;
            }
            
            return new_str;
        };

        return get_new_str(s) == get_new_str(t);
    }
};
