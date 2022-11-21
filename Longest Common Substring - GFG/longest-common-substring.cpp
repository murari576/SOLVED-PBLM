//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(string &s1, string &s2, int i, int j, int &ans, vector<vector<int>> &dp){
        if(i >= s1.length() || j >= s2.length())
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int cnt = 0;
        if(s1[i] == s2[j]){
        cnt = 1+solve(s1, s2, i+1, j+1, ans, dp);
        ans = max(ans, cnt);
        }
        solve(s1, s2, i+1, j, ans, dp);
        solve(s1, s2, i, j+1, ans, dp);
        
        return dp[i][j] = cnt;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        solve(S1, S2, 0, 0, ans, dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends