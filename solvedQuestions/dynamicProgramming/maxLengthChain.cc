// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here

    sort(p,p+n,[](const struct val& a, const struct val& b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second; 
    });
    
    int ans = 0;
    int lastChain = 0;
    
    for(int i=0;i<n;++i){
        if(p[i].first>lastChain){
            ++ans;
            lastChain = p[i].second;
        }
    }
    
    return ans;
}
