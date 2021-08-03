// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        int cnt1=0,cnt2=0,cnt3=0;
        
        for(auto x:s){
            if(x=='{')++cnt1;
            if(x=='}')--cnt1;
            if(x=='[')++cnt2;
            if(x==']')--cnt2;
            if(x=='(')++cnt3;
            if(x==')')--cnt3;
            
            if(cnt1<0||cnt2<0||cnt3<0) return false;
        }
        
        return (cnt1==0&&cnt2==0&&cnt3==0);
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
