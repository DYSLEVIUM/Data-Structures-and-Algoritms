class RandomizedCollection {
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
      mp[val].insert(nums.size());
      nums.push_back(val);
      
      return mp[val].size() == 1;
    }
    
    bool remove(int val) {
      auto it = mp.find(val);
      if(it == mp.end()) {
        return false;
      }
      
      auto free_pos = *it->second.begin();
      it->second.erase(it->second.begin());
      
      int last = nums.back();
      nums[free_pos] = last;
      mp[last].insert(free_pos);
      
      nums.pop_back();
      mp[last].erase(nums.size()); // remove the previous position
      
      if (it->second.size() == 0) {
        mp.erase(it);
      }
      
      return true;
    }
    
    int getRandom() {
      return nums[rand() % nums.size()];
    }

private:
  vector<int> nums;
  unordered_map<int, unordered_set<int>> mp;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
