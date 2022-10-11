class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto get_complex = [](const string &s){
            int pl_pos = find(s.begin(), s.end(), '+') - s.begin();

            int real = stoi(s.substr(0, pl_pos));
            int img = stoi(s.substr(pl_pos + 1, s.size() - 1));
            return make_pair(real, img);
        };
        auto c1 = get_complex(num1), c2 = get_complex(num2);

        int real = (c1.first * c2.first) - (c1.second * c2.second);
        int img = (c1.first * c2.second) + (c1.second * c2.first);
        
        return  to_string(real) + '+' + to_string(img) + 'i';
    }
};
