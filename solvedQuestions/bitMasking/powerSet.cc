// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    multiset<string> se;
		    
		    int len = s.length();
		    
		    for(long long mask = 1; mask < pow(2, len); ++mask){
		        long long teMask = mask;
		        
		        string te = "";
		        
		        int iter = 0;
		        while(teMask){
		            if(teMask&1){
		                te+=s[iter];
		            }
		            
		            teMask>>=1;
		            ++iter;
		        }
		        
		        se.insert(te);
		    }
		    
		    return vector<string>(se.begin(), se.end());
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
