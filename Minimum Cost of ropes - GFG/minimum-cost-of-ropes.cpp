//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long >, greater<long long > > temp;
        long long ans = 0;
        
        for(long long i = 0; i < n; i++){
            temp.push(arr[i]);
        }
        
        while(temp.size() > 1){
            long long a = temp.top();
            temp.pop();
            long long b = temp.top();
            temp.pop();
            
            long long c = a + b;
            ans += c;
            
            temp.push(c);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends