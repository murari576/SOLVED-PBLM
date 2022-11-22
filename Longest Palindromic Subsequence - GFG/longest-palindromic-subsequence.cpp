//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int max(int a, int b){
        if(a > b)
        return a;
        return b;
    }
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if(i == a.length() || j == b.length())
        return 0;
        
    if(dp[i][j] != -1)
    return dp[i][j];
    
    if(a[i] == b[j])
    return dp[i][j] = 1+solve(a, b, i+1, j+1, dp);
    
    int ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
    return dp[i][j] = ans;
    
    }
    int longestPalinSubseq(string A) {
        string B = A;
        int n = A.length();
        reverse(B.begin(), B.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(A, B, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends