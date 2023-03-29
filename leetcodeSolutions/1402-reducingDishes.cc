class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        //  basically finding the place where we are taking all the positive and some negative elements
        int ans = 0, curr = 0, suff = 0;
        for(int i = satisfaction.size() - 1 ; i >= 0; --i){ // we will always try to make the dish with greater value at last
            curr += suff + satisfaction[i]; // suff contains prev, so we don't need to multiply, like 3, 9 -> suff-> 12, 9
            suff += satisfaction[i];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
