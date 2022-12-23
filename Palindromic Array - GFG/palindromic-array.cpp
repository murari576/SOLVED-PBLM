//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool pal(int num){
        string s = to_string(num);
        int i = 0;
        int j = s.length()-1;
        while(i < j){
            if(s[i++] != s[j--])
            return false;
        }
        return true;
    }
    
    int PalinArray(int a[], int n)
    {
    	
    	for(int i = 0; i < n; i++){
    	    int num = a[i];
    	    if(!pal(num))
    	    return false;
    	}
    	return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends