class Solution {
public:
    //  can be done using multiset (mathematical instrument)
    int countVowelStrings(int n) {
        int *dp = new int[5];
        
        for(int i = 0 ; i < 5; ++i) dp[i] = 1;
        
        while(n--){
            for(int i = 1; i < 5; ++i){
                dp[i]+=dp[i-1];
            }
        }
        
        return dp[4];
    }
};
