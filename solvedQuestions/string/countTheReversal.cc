// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s) {
    if(s.length()&1) return -1;
    
    int o = 0;
    int c = 0;
    int ans = 0;
    
    for(int i=0;i<s.length();++i){
        o+=(s[i]=='{');
        c+=(s[i]=='}');
        if(c>o){
            ans+=(c-o);
            swap(c,o);
        }
    }
    
    ans += (abs (c - o)) / 2;
    
    return ans;
}
