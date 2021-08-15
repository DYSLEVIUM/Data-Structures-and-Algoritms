class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      set<int> pos;
      
      for(int i=0;i<nums.size();++i){
        int j = i+1;
        while(j<nums.size() && nums[i]==nums[j]){
          pos.insert(j);
          nums[j++] = INT_MAX;
        }

        i=j-1;
      }
      
      int k = nums.size() - pos.size();
      
      if(!pos.empty()){
        for(int i=0;i<nums.size();++i){
          int fr = *pos.begin();

          if(nums[i]!=INT_MAX && fr<i){
            swap(nums[i], nums[fr]);

            pos.erase(fr);
            pos.insert(i);
          }
        }  
      }
      
      return k;
    }
};
