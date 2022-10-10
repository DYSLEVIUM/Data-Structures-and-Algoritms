class Solution {
public:
    string getHappyString(int n, int k) {
        vector<char> valid{'a', 'b', 'c'};

        vector<string> happy;
        auto recur = [&](const auto &recur, const string &s, const char &prev){
            if(s.size() == n) {
                happy.push_back(s);
                return ;
            }

            for(auto &ch: valid) {
                if(ch != prev) {
                    recur(recur, s + ch, ch);
                }
            }
        };
        recur(recur, "", '#');

        if(happy.size() < k) {
            return "";
        }

        return happy[k - 1];
    }
};
