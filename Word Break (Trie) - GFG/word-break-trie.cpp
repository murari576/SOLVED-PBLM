//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
      bool solve(set<string> &cnt, string &s, int index, vector<int> &dp ){
      if(index >= s.length() ){
          return true;
      }
        if(dp[index] != -1)
           return dp[index];

      string st = "";
      for(int i = index; i < s.length(); i++){
          st.push_back(s[i]);

          if(cnt.count(st) && solve(cnt, s, i+1, dp))
          return dp[index] = true;
      }
      return dp[index] = false;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        vector<int> dp(A.length()+1, -1);
         set<string> st;
         for(auto it:B){
             st.insert(it);
         }
        return solve(st, A, 0, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends