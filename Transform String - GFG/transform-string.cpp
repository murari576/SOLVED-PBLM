//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {

         unordered_map<char, int> mp;
         int n = A.length();
         int m = B.length();
         int i = n-1;
         int j = m-1;
         int cnt = 0;
         
         if(n != m)
         return -1;
         
         for(int i = 0; i < n; i++){
             mp[A[i]]++;
             mp[B[i]]--;
         }
         
         for(int i = 0; i < n; i++){
             if(mp[A[i]] != 0)
             return -1;
         }
         
         while(i >= 0){
             if(A[i] == B[j]){
                 i--;
                 j--;
             }
             else if(A[i] != B[j]){
                 cnt++;
                 i--;
             }
             
         }
         return cnt;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends