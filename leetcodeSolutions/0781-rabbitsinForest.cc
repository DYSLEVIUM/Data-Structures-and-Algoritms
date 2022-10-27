class Solution {
public:
    int numRabbits(vector<int>& answers) {
        /* 
            For rabits with same colors, the answers must be the same. 
            However, when the total amount of that same answer exceeds 'that answer + 1',
            there must be a new color(say [3,3,3,3,3], the first four 3s indicates 4 rabits with the same
            color. The 5th 3 must represent a new color that contains 4 other rabits). 
            We only calculate the amount of rabits with the same color once. Hashmap is used to record the 
            frequency of the same answers. Once it exceeds the range, we clear the frequency and calculate again. 
        */

        unordered_map<int, int> mp;
        
        int res = 0;
        for(int & answer : answers) {
            if(!answer) ++res;
            else {
                if(!mp[answer]) res += answer + 1; // all the other + self
                ++mp[answer]; // mutually seen
                if(mp[answer] == answer + 1) mp[answer] = 0; // means there is a different group
            } 
        }

        return res;
    }
};
