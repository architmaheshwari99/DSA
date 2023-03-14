//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here

        int T[2][1001];
        memset(T, 0, sizeof(T));
        int res=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    T[i%2][j] = 1 + T[(i-1)%2][j-1];
                    if(res<T[i%2][j]){
                        res=T[i%2][j];
                    }
                } else {
                    T[i%2][j] = 0;
                }
            }
        }
        
        return res;
        
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