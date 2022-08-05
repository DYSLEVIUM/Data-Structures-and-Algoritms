//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    void insertHeap(int &x) {
        max_heap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps() {
        int mn_sz = min_heap.size(), mx_sz = max_heap.size();
        if(mx_sz - mn_sz > 1) {
            int tp = max_heap.top();
            max_heap.pop();
            
            min_heap.push(tp);
        }
        
        // checking order
        if(!min_heap.empty()){
            int mn = max_heap.top();
            max_heap.pop();
            
            int mx = min_heap.top();
            min_heap.pop();
            
            if(mn > mx) {
                max_heap.push(mx);
                min_heap.push(mn);
            } else {
                max_heap.push(mn);
                min_heap.push(mx);
            }
        }
    }
    
    //Function to return Median.
    double getMedian() {
        int mn_sz = min_heap.size(), mx_sz = max_heap.size();
        
        double val = -1;
        if((mn_sz + mx_sz) & 1) {
            val = max_heap.top();
        } else {
            int tp1 = max_heap.top();
            int tp2 = min_heap.top();

            val =  (1.0 * tp1 + tp2) / 2;
        }
        
        return val;
    }
    
    private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
