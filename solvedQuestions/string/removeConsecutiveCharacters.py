#User function Template for python3

class Solution:
    def removeConsecutiveCharacter(self, S):
        n = len(S)
        ans = S[0]
        for i in range(1, n):
            if ans[-1] != S[i]:
                ans += S[i]
        return ans
      
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        s = input()
        ob = Solution()
        print(ob.removeConsecutiveCharacter(s))

# } Driver Code Ends
