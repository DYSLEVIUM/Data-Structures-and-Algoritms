class Solution {
public:
    int countPoints(string rings) {
      vector<vector<int>> rods(10, vector<int>(3));
      int n = rings.length();
      
      unordered_map<char,int> mp;
      mp['R'] = 0;
      mp['G'] = 1;
      mp['B'] = 2;
      
      for(int i=0;i<n;i+=2){
        char color = rings[i];
        int ring_rod = rings[i+1]-'0';
        
        ++rods[ring_rod][mp[color]];
      }
      
      int ans = 0;
      
      for(int i=0;i<10;++i){
        int curr_rod = INT_MAX;
        for(auto& color:mp) curr_rod = min(curr_rod, rods[i][color.second]);          
       
        ans += curr_rod!=0;
      }
      
      return ans;
    }
};
