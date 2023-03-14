//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here

        int T[1001]={0};
        memset(T, 0, sizeof(T));
        int res=0;
        
        for(int i=1;i<=n;i++){
            int prev = T[0];
            for(int j=1;j<=m;j++){
                int temp = T[j];
                if(S1[i-1]==S2[j-1]){
                    T[j] = 1 + prev;
                    if(res<T[j]){
                        res=T[j];
                    }
                } else {
                    T[j]=0;
                }
                prev=temp;
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