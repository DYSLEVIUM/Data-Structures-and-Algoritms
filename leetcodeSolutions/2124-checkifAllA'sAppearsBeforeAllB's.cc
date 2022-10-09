class Solution {
public:
    bool checkString(string s) {
        int n = s.size();

        int ptr1 = s[0] == 'a' ? 0 : -1;
        while(ptr1 >= 0 && ptr1 < n && s[ptr1] == 'a') {
            ++ptr1;
        }
        ptr1 -= s[0] == 'a';

        int ptr2 = s[n - 1] == 'b' ? n - 1 : n;
        while(ptr2 >= 0 && ptr2 < n && s[ptr2] == 'b') {
            --ptr2;
        }
        ptr2 += s[n - 1] == 'b';

        return ptr1 + 1 == ptr2;
    }
};
