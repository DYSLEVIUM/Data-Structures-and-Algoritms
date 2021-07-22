// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        int totXor = 0;
        
        for(int i = 0; i < nums.size(); ++i) totXor ^= nums[i];
        
        int rightMostSetBit = totXor & ~(totXor - 1);
        
        int a1 = 0;
        int a2 = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] & rightMostSetBit) a1 ^= nums[i]; 
            else a2 ^= nums[i];
        }
        
        if(a1 < a2) return vector<int>{a1, a2};

        return vector<int>{a2, a1}; 
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
