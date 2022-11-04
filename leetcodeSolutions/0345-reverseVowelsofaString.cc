class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();

        int lo = 0, hi = n - 1;
        while(lo < hi) {
            while(lo < n && !vowels.count(s[lo])) ++lo;
            while(hi >= 0 && !vowels.count(s[hi])) --hi;

            if(lo >= hi) break;
            
            swap(s[lo++], s[hi--]);
        }

        return s;
    }
};
