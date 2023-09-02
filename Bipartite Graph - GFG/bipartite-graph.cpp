//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, vector<int> &vis, int col, vector<int> adj[]){
        vis[node] = col;
        
        for(auto it:adj[node]){
            if(vis[it] == -1){
                if(dfs(it, vis, !col, adj))
                return true;
            }
            else if(vis[it] == col)
                 return true;
        }
        return false;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V, -1);
	    vector<int> pathvis(V, 0);
	    
	    for(int i = 0; i < V; i++){
	        if(vis[i] == -1)
	        if(dfs(i, vis, 0, adj))
	        return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends