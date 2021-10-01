class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target=num;
        ++k;
        do {
            --k;
        } while(k&&next_permutation(target.begin(), target.end()));
        
        int ans = 0;
        
        for(int i=0;i<num.size();++i){
            if(num[i]!=target[i]){
                int j = i;
                while(j<num.size() && target[i]!=num[j]) ++j;
                
                ans+=(j-i);
                
                for(int k = j;k>=i+1;--k){
                    swap(num[k], num[k-1]);
                }
            }
        }
        
        return ans;
    }
};
