//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], int l, int r, int mid){
        long long int n1 = mid - l + 1;
        long long int n2 = r - mid;
        
        long long int a[n1];
        long long int b[n2];
        
        for(int i = 0; i < n1; i++){
            a[i] = arr[i+l];
        }
        
        for(int j = 0 ; j < n2 ; j++){
            b[j] = arr[mid+1+j];
        }
        
        long long int i = 0, j = 0, k = l;
        long long int cnt = 0;
        
        while(i < n1 && j < n2){
            if(a[i] > b[j]){
                arr[k++] = b[j++];
                cnt += n1 - i;
            }
            else
                arr[k++] = a[i++];
        }
        
        while(i < n1)
            arr[k++] = a[i++];
       
        while(j < n2)
            arr[k++] = b[j++];
       
        return cnt;
    }
    
    long long int solve(long long arr[], long long l, long long r){
        long long mid = (l+r)/2;
        long long inv = 0;
        
        if(l < r){
        inv += solve(arr, l, mid);
        inv += solve(arr, mid+1, r);
        inv += merge(arr, l, r, mid);
        }
        return inv;
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return solve(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends