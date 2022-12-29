//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1000000007;
    private:
    long long int solve(string &str, int i, int j, vector<vector<int>> &dp){
        if(i > j)
        return 0;
        
        if(i == j)
        return 1;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        if(str[i] == str[j])
        return dp[i][j] = (1 + solve(str, i+1, j, dp) + solve(str, i, j-1, dp))%mod;
        
        else
        return dp[i][j] = (mod + solve(str, i+1, j, dp) + solve(str, i, j-1, dp) - solve(str, i+1, j-1, dp))%mod;
    }
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       
       int n = str.length();
       vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
       return solve(str, 0, n-1, dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends