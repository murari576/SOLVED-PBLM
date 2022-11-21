//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int n, int m, vector<vector<int>> &mat, int i, int j, int &maxi, 
                            vector<vector<int>> &dp){
                                
        if(i >= n || j >= m)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int diagonal = solve(n, m, mat, i+1, j+1, maxi, dp) ;
        int right = solve(n, m, mat, i, j+1, maxi, dp) ;
        int bottom = solve(n, m, mat, i+1, j, maxi, dp) ;
        
        if(mat[i][j] == 1){
        int ans = min(diagonal, min(right, bottom)) + 1;
        maxi = max(maxi, ans);
        return dp[i][j] = ans ;
        }
    
    }
    
    
    int solveTab(int n, int m, vector<vector<int>> mat, int &maxi){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j>= 0; j--){
        int diagonal = dp[i+1][j+1];
        int right = dp[i][j+1] ;
        int bottom = dp[i+1][j] ;
        
        if(mat[i][j] == 1){
        int ans = min(diagonal, min(right, bottom)) + 1;
        maxi = max(maxi, ans);
        dp[i][j] = ans ;
               }
                
            }
        }
        
        return dp[0][0];
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
    int maxi = 0;
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // solve(n, m, mat, 0, 0, maxi, dp);
    solveTab(n, m, mat, maxi);
    return maxi;
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends