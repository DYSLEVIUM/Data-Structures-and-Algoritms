// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        const int MXN = 1e5;
        vector<int> digits(MXN);
        digits[0] = 1;
        
        int resSize = 1;

        for (int i = 2; i <= N; ++i) {
            int carry = 0;
    
            for (int j = 0; j < resSize; ++j) {
                int prod = digits[j] * i + carry;
    
                digits[j] = prod % 10;
                carry = prod / 10;
            }
    
            while (carry) {
                digits[resSize++] = carry % 10;
                carry /= 10;
            }
        }
    
        
        vector<int> ans(digits.begin(), digits.begin()+resSize);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
