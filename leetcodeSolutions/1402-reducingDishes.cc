class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        //  basically finding the place where we are taking all the positive and some negative elements
        int ans = 0;
        int curr = 0;
        int suff = 0;
        
        for(int i=satisfaction.size()-1;i>=0;--i){
            curr += suff + satisfaction[i];
            suff += satisfaction[i];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
