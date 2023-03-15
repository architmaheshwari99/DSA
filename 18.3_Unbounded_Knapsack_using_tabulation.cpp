//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int T[1001][1001];
        memset(T, 0, sizeof(T));
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(j>=wt[i-1]){
                    T[i][j] = max(T[i-1][j], val[i-1] + T[i][j-wt[i-1]]);
                } else {
                    T[i][j] = T[i-1][j];
                }
            }
        }
        
        return T[N][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends