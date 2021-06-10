// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

//https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#
class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        
        sort(arr,arr+n);
        
        string n1 = "";
        string n2 = "";
        
        for (int i = 0; i < n; ++i) {
            if (i & 1)
              n1 += to_string(arr[i]);
            else
              n2 += to_string(arr[i]);
        }
        
        auto add = [](string s1, string s2) {
            string ans = "";
        
            int carry = 0;
        
            while (s1.length() && s2.length()) {
              int c1 = s1[s1.length() - 1] - '0';
              int c2 = s2[s2.length() - 1] - '0';
        
              int expr = c1 + c2 + carry;
              ans += to_string(expr % 10);
              carry = expr / 10;
        
              s1.pop_back();
              s2.pop_back();
            }
        
            while (s1.length()) {
              ans += to_string((s1[s1.length() - 1] - '0' + carry) % 10);
              carry = (s1[s1.length() - 1] - '0' + carry) / 10;
              s1.pop_back();
            }
        
            while (s2.length()) {
              ans += to_string((s2[s2.length() - 1] - '0' + carry) % 10);
              carry = (s2[s2.length() - 1] - '0' + carry) / 10;
              s2.pop_back();
            }
            
            if (carry) ans += to_string(carry);
        
            while (ans[ans.length() - 1] == '0') ans.pop_back();
        
            reverse(ans.begin(), ans.end());
            return ans;
        };
        
        return add(n1, n2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
