class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        
        int i=0,j=piles.size()-1;
        
        int ans = 0;
        while(i<j){
            int x = piles[i++];
            int y = piles[i++];
            int z = piles[j--];
            
            ans+=x+y+z-max({x,y,z})-min({x,y,z});
        }
        
        return ans;
    }
};
