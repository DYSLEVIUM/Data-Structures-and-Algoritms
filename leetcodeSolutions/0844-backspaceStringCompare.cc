class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ptr_s = s.length() - 1, ptr_t = t.length() - 1;
        int skip_s = 0, skip_t = 0;
        
        while(ptr_s >= 0 || ptr_t >= 0) {
            while(ptr_s >= 0) {
                if(s[ptr_s] == '#') {
                    ++skip_s, --ptr_s;
                } else if(skip_s > 0) {
                    --skip_s, --ptr_s;
                } else {
                    break;
                }
            }
            
            while(ptr_t >= 0) {
                if(t[ptr_t] == '#') {
                    ++skip_t, --ptr_t;
                } else if(skip_t > 0) {
                    --skip_t, --ptr_t;
                } else {
                    break;
                }
            }
            
            if(ptr_s >= 0 && ptr_t >= 0 && s[ptr_s] != t[ptr_t]) return false;
            
            if((ptr_s >= 0) != (ptr_t >= 0)) return false;
            
            --ptr_s, --ptr_t;
        }
        
        return true;
    }
};
