//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int T[1001][1001];
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(T, -1, sizeof(T));
       
       for(int i=0;i<=n;i++){
           for(int j=0;j<=W;j++){
               if(i==0 || j==0) {
                   T[i][j]=0;
               } else if(wt[i-1]<=j){
                   T[i][j] = max(T[i-1][j], val[i-1]+T[i-1][j-wt[i-1]]);
               } else {
                   T[i][j] = T[i-1][j];
               }
               
           }
       }
       
       return T[n][W];
       
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends