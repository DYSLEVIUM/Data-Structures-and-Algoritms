//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2) {
        auto normalize = [](const string &s){
            unordered_map<char, char> mp;
            char ch_ptr = 'a';
            
            for(auto &ch : s) {
                if(mp.find(ch) == mp.end()) {
                    mp[ch] = ch_ptr++;                    
                }
            }

            string norm = "";
            for(auto &ch : s) {
                norm += mp[ch];
            }
            
            return norm;
        };
        
        return normalize(str1) == normalize(str2);
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
