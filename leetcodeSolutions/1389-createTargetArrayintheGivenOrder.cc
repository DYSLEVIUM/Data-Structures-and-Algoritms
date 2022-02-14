class solution {
public:
    vector<int> createtargetarray(vector<int>& nums, vector<int>& index) {      
      int n = nums.size();
      vector<int> res;

      for(int i=0;i<n;++i) res.insert(res.begin() + index[i], nums[i]);
      
      return res;
    }
};
