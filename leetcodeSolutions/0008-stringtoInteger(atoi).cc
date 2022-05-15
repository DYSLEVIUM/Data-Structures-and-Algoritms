class Solution {
public:
    int myAtoi(string s) {
        reverse(s.begin(), s.end());

        //  remove leading whitespace
        while(!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        
        //  check negative
        bool is_negative = false;
        
        if(!s.empty() && s.back() == '-') {
            is_negative = true;
            s.pop_back();
        } else if(!s.empty() && s.back() == '+') {
            s.pop_back();
        }
        
        //  get the number
        unsigned long long num = 0;
        
        while(!s.empty() && (s.back() >= '0' && s.back() <= '9')){
            num = num * 10 + s.back() - '0';
            s.pop_back();
            
            if(num > (1LL << 31)) {
                break;
            }
        }

        //  clamp the number
        if(is_negative) {
            if(num > (1LL << 31)) {
                num = (1LL << 31);
            }
            
            num *= -1;
        } else {
            if(num > (1LL << 31) - 1) {
                num = (1LL << 31) - 1;
            }    
        }
        
        return num;
    }
};
