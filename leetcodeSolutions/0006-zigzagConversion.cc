class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        string newStr = "";
        
        /*
            P   | A   | H   | N
            A P | L S | I I | G
            Y   | I   | R   |
        */
        
        //the size of a cycle(period)
        int cycle = 2 * numRows - 2;
        
        for(int i = 0; i < numRows; ++i) {
            for(int j = i; j < s.length(); j += cycle) {
                newStr += s[j];
                
                //  every period except the first and the last will contain 2 elements if the string has not ended
                if(i==0 || i==numRows-1) continue;

                int second_ele_idx = (j - i) + cycle - i;
                if(second_ele_idx < s.length()) newStr += s[second_ele_idx];
            }
        }
        
        return newStr;
    }
};
