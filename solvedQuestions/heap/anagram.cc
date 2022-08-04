//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        const int CHAR_SET = 26;
        auto get_fa = [&CHAR_SET](const string &x){
            int *fa = new int[CHAR_SET]{0};
            for(auto &ch : x) {
                ++fa[ch - 'a'];
            }
            return fa;
        };
        
        
        auto fa_a = get_fa(a), fa_b = get_fa(b);

        bool is_ana = true;
        for(int i = 0; i < CHAR_SET; ++i) {
            is_ana &= fa_a[i] == fa_b[i];
        }
        
        delete[] fa_a;
        delete[] fa_b;
    
        return is_ana;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends
