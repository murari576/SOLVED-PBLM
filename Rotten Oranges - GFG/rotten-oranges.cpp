//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        int tm = 0;
        int cnt = 0;
        int newcnt = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        int delx[] = {1, -1, 0, 0};
        int dely[] = {0, 0, -1, 1};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
                }
                
                else
                vis[i][j] = 0;
                
                if(grid[i][j] == 1)
                cnt++;
            }
        }
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(tm, t);
            
            for(int i = 0; i < 4; i++){
                int nrow = r + delx[i];
                int ncol = c + dely[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0&& ncol < m 
                && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    newcnt++;
                }
            }
        }
        if(cnt != newcnt)
        return -1;
        return tm;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends