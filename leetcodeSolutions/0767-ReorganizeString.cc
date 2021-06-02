class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> maxHeap;
        
        map<char, int> mp;
        
        for(auto x:s) ++mp[x];
        
        string newStr = "";
        
        for(auto x:mp){
            maxHeap.push({x.second,x.first});
        }
        
        while(maxHeap.size()>=2){
            pair<int, char> ff=maxHeap.top();
            
            maxHeap.pop();
            
            pair<int, char> ss=maxHeap.top();
            
            maxHeap.pop();
            
            newStr+=ff.second;
            newStr+=ss.second;
            
            if(ff.first-1!=0)
            maxHeap.push({ff.first-1,ff.second});
            
            if(ss.first-1!=0)
            maxHeap.push({ss.first-1,ss.second});
        }
        
        if(!maxHeap.empty()){
            if(maxHeap.top().first>1) 
            {
                newStr="";
                return newStr;                
            }
            for(int i=0;i<maxHeap.top().first;++i)
                newStr+=maxHeap.top().second;  
        }
        
        return newStr;
    }
};
