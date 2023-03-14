//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:

    int longSubStr(string S1, string S2, int m, int n, int maxi){
        if(m==0 || n==0) return 0;
        
        if(S1[m-1]==S2[n-1]){
            maxi = longSubStr(S1, S2, m-1, n-1, maxi+1);

        } 
        
        return max(maxi, max(longSubStr(S1,S2,m,n-1,0), longSubStr(S1, S2, m-1, n, 0)));
        
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int maxi=0;
        return longSubStr(S1, S2, m, n, maxi);
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends