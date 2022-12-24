//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
          
           int leftmaxx = arr[0];
           int rightmaxx = arr[n-1];
          long long int l =0, r = n-1, res = 0;
          
          while(l < r){
              if(leftmaxx < rightmaxx){
              l++;
              leftmaxx = max(leftmaxx, arr[l]);
              if(leftmaxx-arr[l]>=0)
              res += leftmaxx-arr[l];
              }
              
              else{
                  r--;
                  rightmaxx = max(rightmaxx, arr[r]);
                  if(rightmaxx - arr[r] >= 0)
                  res += rightmaxx - arr[r];
              }
          }
          return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends