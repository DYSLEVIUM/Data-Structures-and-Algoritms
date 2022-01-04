// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    class fenwick_tree{
        private:
            long long _size;
            vector<long long> _data;
        public:
            fenwick_tree(long long n):_size(n+1){
                _data.assign(_size+1, 0);
            }
            
            long long query(long long x){
                long long sum = 0; 
                while(x>0){
                    sum +=_data[x];
                    x-=(x&-x);
                }
                
                return sum;
            }
            
            void update(long long x){
                while(x<=_size){
                    ++_data[x];
                    x+=(x&-x);
                }
            }
    };
  
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        auto convert_to_relative_ordering = [](){
            int temp[N];
            for (int i=0; i<N; i++) temp[i] = arr[i];
            sort(temp, temp+N);
         
            // Traverse all array elements
            for (int i=0; i<N; i++)
            {
                // lower_bound() Returns pointer to the first element
                // greater than or equal to arr[i]
                arr[i] = lower_bound(temp, temp+N, arr[i]) - temp + 1;
            }  
        };
        
        fenwick_tree BIT(N+1);
            
        long long int ans = 0;

        for(int i=N-1;i>=0;--i){
            ans+= BIT.query(arr[i]-1);
            BIT.update(arr[i]);
        }
        
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
