class Solution {
	public:
	int LongestRepeatingSubsequence(string s){
        // Code here
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1));
        
        for(int i=0;i<s.length()+1;++i){
            for(int j=0;j<s.length()+1;++j){
                if (i==0 || j==0) dp[i][j]=0;
                else if(s[i-1]==s[j-1] && i!=j){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[s.length()][s.length()];
	}
};
