//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
       void solve(vector<string> &ans, string temp, set<string> cnt, string s, int index ){
      if(index >= s.length() ){
          temp.pop_back();
          ans.push_back(temp);
          return;
      }

      string st = "";
      for(int i = index; i < s.length(); i++){
          st.push_back(s[i]);

          if(cnt.count(st))
          solve(ans, temp + st + " ", cnt, s, i+1);
      }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
         vector<string> ans;
         string str = "";
         set<string> st;
         for(auto it:dict){
             st.insert(it);
         }
        solve(ans, str, st, s, 0);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends