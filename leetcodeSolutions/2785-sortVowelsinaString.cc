// class Solution {
// public:
//     string sortVowels(string & s) {
//         unordered_set<char> vowels;
//         for(const char & c: "aeiou") {
//             vowels.insert(c | ' '); // lowercase
//             vowels.insert(c & '_'); // uppercase
//         }

//         vector<char> v_arr;
//         v_arr.reserve(s.size());

//         for(const char & c: s) {
//             if(vowels.count(c)) {
//                 v_arr.push_back(c);
//             }
//         }

//         sort(v_arr.begin(), v_arr.end());

//         int i = 0;
//         for(auto & c: s) {
//             if(vowels.count(c)) {
//                 c = v_arr[i++];
//             }
//         }

//         return s;
//     }
// };

class Solution {
public:
    string sortVowels(string & s) {
        unordered_set<char> vowels;
        for(const char & c: "aeiou") {
            vowels.insert(c | ' '); // lowercase
            vowels.insert(c & '_'); // uppercase
        }

        // counting sort
        unordered_map<char, int> count;
        for(const char & c: s) {
            if(vowels.count(c)) {
                ++count[c];
            }
        }

        string sorted_vowels = "AEIOUaeiou";
        int j = 0;
        for(char & c: s) {
            if(vowels.count(c)) {
                while(count[sorted_vowels[j]] == 0) { // go to valid vowel
                    ++j;
                }
                c = sorted_vowels[j];
                --count[sorted_vowels[j]];
            }
        }

        return s;
    }
};
