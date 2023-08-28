//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    string st = "DRUL";
    
    void solve(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &m, int n,
                 vector<string> &ans, string temp){
                     
        if(r == n-1 && c == n-1){
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0 && 
               m[nr][nc] == 1){
                   temp.push_back(st[i]);
                   vis[nr][nc] = 1;
                   solve(nr, nc, vis, m, n, ans, temp);
                   vis[nr][nc] = 0;
                   temp.pop_back();
               }
        }
     }
     
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> ans;
        string temp = "";
        
        if(m[0][0] == 0){
            temp = "-1";
            ans.push_back(temp);
            return ans;
        }
        vis[0][0] = 1;
        solve(0, 0, vis, m, n, ans, temp);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends