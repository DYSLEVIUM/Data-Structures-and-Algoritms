class Solution {
public:
    int minOperations(int n) {
        int totalElements;
        if(n&1){
            //  series starts with 0
            totalElements = n/2+1;
            return totalElements*(totalElements-1);
        }else{
            //  series starts with 1
            totalElements = n/2;
            return totalElements*totalElements;
        }
    }
};
