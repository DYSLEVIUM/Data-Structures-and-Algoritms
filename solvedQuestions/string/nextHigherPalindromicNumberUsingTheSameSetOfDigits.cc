//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string next_perm(string s) {
        int n = s.length();
        int inversion_point = -1;
        for(int i = n - 2; i >= 0; --i) {
            if(s[i] < s[i + 1]) {
                inversion_point = i;
                break;
            }
        }
        
        if(inversion_point != -1) {
            for(int i = n - 1; i >= 0; --i) {
                if(s[i] > s[inversion_point]) {
                    swap(s[i], s[inversion_point]);
                    break;
                }
            }
            reverse(s.begin() + inversion_point + 1, s.end());
            
            return s;
        }
        
        return "-1";
    }
    
    string nextPalin(string s) { 
        int n = s.length();
        
        bool is_odd = n & 1;
        char mid;
        if(is_odd) {
            mid = s[n / 2];
        }
        
        string next = next_perm(s.substr(0, n / 2));
        if(next == "-1") {
            return "-1";
        }
        
        string ans = next;
        if(is_odd) {
            ans += mid;
        }
        ans += string(next.rbegin(), next.rend());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
