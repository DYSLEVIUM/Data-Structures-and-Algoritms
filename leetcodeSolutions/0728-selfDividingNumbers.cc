class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        auto check = [](const int &num){
            int copy_num = num;
            while(copy_num) {
                int last_digit = copy_num % 10;
                if(last_digit == 0 || (num % last_digit)) return false;
                copy_num /= 10;
            }
            
            return true;
        };
        
        vector<int> ans;
        for(int i = left; i <= right; ++i) {
            if(check(i)) ans.push_back(i);
        }
        
        return ans;
    }
};
