// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &s) {
    // code here
    
    map<char,int> mp;
    
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    
    int sum=0;
    
    for(int i=0;i<s.length()-1;++i){
        if(mp[s[i]]>=mp[s[i+1]]){
            sum+=mp[s[i]];
        }else{
            sum-=mp[s[i]];
        }
    }
    
    sum+=mp[s[s.length()-1]];
    
    return sum;
}
