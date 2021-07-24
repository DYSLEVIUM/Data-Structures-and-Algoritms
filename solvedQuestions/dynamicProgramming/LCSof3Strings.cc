// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
{
    // your code here
    typedef long long ll;
    ll*** dp = new ll**[n1 + 1];

        for (ll i{}; i < n1 + 1; ++i) {
            dp[i] = new ll*[n2 + 1];

            for (ll j{}; j < n2 + 1; ++j)
                dp[i][j] = new ll[n3 + 1];
        }

        for (ll i{}; i < n1 + 1; ++i) {
            for (ll j{}; j < n2 + 1; ++j) {
                for (ll k{}; k < n3 + 1; ++k) {
                    if (i == 0 || j == 0 || k == 0)
                        dp[i][j][k] = 0;
                    else if (s1[i - 1] == s2[j - 1] && s3[k - 1] == s1[i - 1])
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    else
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }

    return dp[n1][n2][n3];
}
