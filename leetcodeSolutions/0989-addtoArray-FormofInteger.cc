class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string ks = to_string(k);

        reverse(num.begin(), num.end());
        reverse(ks.begin(), ks.end());

        int carry = 0;
        int p1 = 0, p2 = 0;
        while(p1 < num.size() && p2 < ks.size()) {
            int total = num[p1] + (ks[p2] - '0') + carry;
            
            carry = total / 10;
            total %= 10;

            num[p1] = total;

            ++p1, ++p2;
        }

        while(p1 < num.size()) {
            int total = num[p1] + carry;

            carry = total / 10;
            total %= 10;

            num[p1] = total;
            
            ++p1;
        }

        while(p2 < ks.size()) {
            int total = (ks[p2] - '0') + carry;

            carry = total / 10;
            total %= 10;

            num.push_back(total);

            ++p2;
        }

        if(carry) num.push_back(carry);
        
        reverse(num.begin(), num.end());
        
        return num;
    }
};
