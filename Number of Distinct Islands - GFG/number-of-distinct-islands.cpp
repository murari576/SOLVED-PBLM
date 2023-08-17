//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    void solve(int row, int col, vector<vector<bool>> &vis, 
    vector<vector<int>>& grid, vector<pair<int, int>> &temp, int row0, int col0){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        temp.push_back({row-row0, col-col0});

        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                solve(nrow, ncol, vis, grid, temp, row0, col0);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        queue<pair<int, int> > q;
        set<vector<pair<int, int>>> st;
        

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    vector<pair<int, int>> temp;
                    solve(i, j, vis, grid, temp, i, j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends