//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detect(int src, int vis[], int parvis[], vector<int> adj[]){
        vis[src] = 1;
        parvis[src] = 1;
        
        for(auto it:adj[src]){
            if(!vis[it]){
                if(detect(it, vis, parvis, adj) == true)
                return true;
            }
            else if(parvis[it])
                return true;
        }
        parvis[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int parvis[V] = {0};
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                if(detect(i, vis, parvis, adj) == true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends