// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    
    int case1 = 0;
    
    for(int i=0;i<s.length();++i){
        if(i&1){
            if(s[i]=='0') ++case1;
        }else{
            if(s[i]=='1') ++case1;
        }
    }
    
    int case2 = 0;
    
    for(int i=0;i<s.length();++i){
        if(i&1){
            if(s[i]=='1') ++case2;
        }else{
            if(s[i]=='0') ++case2;
        }
    }
    
    return min(case1, case2);
}
