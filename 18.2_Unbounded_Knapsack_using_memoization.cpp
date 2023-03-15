//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int T[1001][1001];
    int unboundedKnapsack(int N, int W, int val[], int wt[]){
        if(N==0 || W==0) return 0;
        
        if(T[N][W]!=-1) return T[N][W];
        
        if(wt[N-1]<=W){
            return T[N][W] = max(unboundedKnapsack(N-1, W, val, wt), val[N-1]+unboundedKnapsack(N, W-wt[N-1], val, wt));
        } else {
            return T[N][W] = unboundedKnapsack(N-1, W, val, wt);
        }
        
    }



    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(T, -1, sizeof(T));
        return unboundedKnapsack(N, W, val, wt);
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