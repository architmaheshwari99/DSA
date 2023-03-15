//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string X) {
        //code here
        
        string Y = X;
        reverse(Y.begin(), Y.end());
        int m,n;
        m= Y.size();
        n= m;
        
        int T[m+1][n+1];
        memset(T, 0, sizeof(T));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1])
                    T[i][j] = 1+T[i-1][j-1];
                else{
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
                }
            }
        }
        
        return T[m][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends