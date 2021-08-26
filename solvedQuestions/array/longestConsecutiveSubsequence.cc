// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        map<int, bool> mp;
        
        for(int i=0;i<N;++i) mp[arr[i]]=true;
        
        int curr=0;
        int ans=0;
        
        int prev=mp.begin()->first;
        
        for(auto x:mp){
            if(x.first==prev+1) ++curr;
            else curr=1;
            
            prev=x.first;
            
            ans = max(curr, ans);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
