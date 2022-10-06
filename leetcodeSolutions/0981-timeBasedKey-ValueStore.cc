class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(const string &key, const string &value, const int &timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        return it == mp[key].begin() ? "" : prev(it)->second;
    }

private:
    unordered_map<string, map<int, string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

