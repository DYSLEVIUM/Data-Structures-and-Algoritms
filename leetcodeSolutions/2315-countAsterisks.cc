class Solution {
public:
    int countAsterisks(string s) {
        bool open = true;
        
        int cnt = 0;
        for(char &ch: s) {
            if(ch == '|') {
                open = !open;
            }

            cnt += ch == '*' && open;
        }
        
        return cnt;
    }
};
