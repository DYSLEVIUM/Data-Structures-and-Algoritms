class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1.length()!=s2.length()) return -1;
        
        int xCnt=0, yCnt=0;
        
        for(int i=0;i<s1.length();++i){
            xCnt+=s1[i]=='x';
            yCnt+=s1[i]=='y';

            xCnt+=s2[i]=='x';
            yCnt+=s2[i]=='y';
        }
        
        if(xCnt&1 || yCnt&1) return -1;
        
        xCnt = 0, yCnt = 0;
        for(int i=0;i<s1.length();++i){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x') ++xCnt;
                else ++yCnt;
            }
        }
        
        return (xCnt/2+yCnt/2+(xCnt&1)+(yCnt&1));
    }
};
