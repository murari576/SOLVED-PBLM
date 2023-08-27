//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int ans = INT_MAX;
	    int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
	    int dy[8] = {2, -2, 2, -2, 1, -1, -1, 1};
	    
	    vector<vector<int>> vis(N, vector<int>(N, 0));
	    queue<pair<pair<int, int>, int>> q;
	    int u = KnightPos[0]-1;
	    int v = KnightPos[1]-1;
	    int x = TargetPos[0]-1;
	    int y = TargetPos[1]-1;
	    q.push({{u,v},0});
	    
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int cnt = q.front().second;
	        q.pop();
	        
	        for(int i = 0; i < 8; i++){
	            int nr = dx[i] + r;
	            int nc = dy[i] + c;
	            
	            if(nr >= 0 && nr < N && nc >= 0 && nc < N && vis[nr][nc] == 0){
	                vis[nr][nc] = 1;
	                q.push({{nr, nc}, cnt+1});
	                if(nr == x && nc == y){
	                    ans = min(ans, cnt+1);
	                }
	            }
	        }
	    }
	    if(ans == INT_MAX)
	    return 0;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends