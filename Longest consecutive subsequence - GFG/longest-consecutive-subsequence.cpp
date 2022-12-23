//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      int maxi = 0;
      unordered_set<int> st;
      
      for(int i = 0; i < N; i++){
          
          maxi = max(maxi, arr[i]);
          st.insert(arr[i]);
      }
      int cnt = 0, temp = 0;
      
      for(int i = 1; i <= maxi; i++){
          if(st.find(i) != st.end()){
          temp++;
          cnt = max(temp, cnt);
          }
          
          else
          temp = 0;
      }
      return cnt;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends