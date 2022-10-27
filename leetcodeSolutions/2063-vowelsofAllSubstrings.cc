class Solution {
public:
    long long countVowels(const string & word) {
        int n = word.size();
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            if(vowels.count(word[i])) ans += 1LL * (i + 1) * (n - i);
        }

        return ans;
    }
};
