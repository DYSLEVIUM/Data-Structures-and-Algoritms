// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        if(str1.length()!=str2.length()) return false;
        
        //  first to second mapping check
        int fa1[26];
        memset(fa1,-1,sizeof(fa1));
        
        for(int i=0;i<str1.length();++i){
            if(fa1[str1[i]-'a']==-1){
                fa1[str1[i]-'a']=str2[i]-'a';
            }else if(fa1[str1[i]-'a']!=str2[i]-'a') return false;
        }

        //  second to first mapping check
        int fa2[26];
        memset(fa2,-1,sizeof(fa2));
        
        for(int i=0;i<str2.length();++i){
            if(fa2[str2[i]-'a']==-1){
                fa2[str2[i]-'a']=str1[i]-'a';
            }else if(fa2[str2[i]-'a']!=str1[i]-'a') return false;
        }
        
        return true;
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends
