//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int T[2][1001];
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(T, 0, sizeof(T));
       bool b;
       
       for(int i=1;i<=n;i++){
           b = i % 2;
           for(int j=1;j<=W;j++){
                if(wt[i-1]<=j){
                   T[i%2][j] = max(T[1-(i%2)][j], val[i-1]+T[1-(i%2)][j-wt[i-1]]);
               } else {
                   T[i%2][j] = T[1-(i%2)][j];
               }
               
           }
       }
       
       return T[b][W];
       
       
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