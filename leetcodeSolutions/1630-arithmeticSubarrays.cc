class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        auto check = [&nums](const int& l_idx, const int& r_idx){
            auto [minn, maxx] = minmax_element(nums.begin() + l_idx, nums.begin() + r_idx + 1);

            if(*minn == *maxx) return true;

            int curr_len = r_idx - l_idx + 1;

            //  if the common differece is not a integer
            if((*maxx - *minn) % (curr_len - 1)) return false;
            int comm_diff = (*maxx - *minn) / (curr_len - 1);
                
            //  using the formula: a_n = a_0 + (n - 1) / d
            unordered_set<int> se;
            for(int i = l_idx; i <= r_idx; ++i) {
                //  if the number is not divisible by comm_diff
                if((nums[i] - *minn) % comm_diff) return false;
                
                int pos = ((nums[i] - *minn) / comm_diff) + 1;
                if(se.find(pos) != se.end()) return false;
                se.insert(pos);
            }
            
            return true;
        };        
        
        int m = l.size();
        vector<bool> ans(m);
        for(int i = 0; i < m; ++i) {
            ans[i] = check(l[i], r[i]);   
        }
        
        return ans;
    }
};
