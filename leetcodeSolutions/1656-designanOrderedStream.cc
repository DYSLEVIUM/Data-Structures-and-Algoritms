class OrderedStream {
public:
    vector<string> stream;
    
    int ptr = 0;
        
    OrderedStream(int n): stream(n) {}
    
    vector<string> insert(int idKey, string value) {
        stream[idKey-1] = value;
        
        int n = stream.size();
        
        vector<string> res;
        while(ptr<n && !stream[ptr].empty()) res.push_back(stream[ptr++]);
        
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
