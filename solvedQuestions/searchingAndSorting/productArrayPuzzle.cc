// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        //can be done with prefix and suffix array
        long long int res = 1;
        
        vector<int> zeroIdx;
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] != 0) res *= nums[i];
            
            if(nums[i] == 0 && zeroIdx.size() < 2) zeroIdx.push_back(i);
        }
        
        if(zeroIdx.size() > 1) return vector<long long int>(n, 0);
        
        vector<long long int> ans(n);
        
        for(int i = 0; i < n; ++i){
            if(!zeroIdx.empty()) {
                if(i == zeroIdx[0]) ans[i] = res;
                else ans[i] = 0 * 1LL;
            }
            else ans[i] = res / nums[i];
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
