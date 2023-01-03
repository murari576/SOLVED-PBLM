//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length())
        return false;
        // Your code here
        unordered_map<char, char> mp;
        unordered_set<char> st;
        
        for(int i = 0; i < str1.length(); i++){
            char sc = str1[i];
            char tc = str2[i];
            
            if(mp.count(sc)){
                if(mp[sc] != tc)
                return false;
                
            }
            
            else{
                if(st.count(tc))
                return false;
                mp[sc] = tc;
                st.insert(tc);
            }
            
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends