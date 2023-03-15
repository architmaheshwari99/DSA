//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int T[1001][1001];
  
  int maxProfit(int price[], int len[], int n, int maxLen){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(len[i-1]<=j){
                T[i][j] = max(T[i-1][j], price[i-1]+T[i][j-len[i-1]]);
            } else {
                T[i][j] = T[i-1][j];
            }
        }
    }
    return T[n][n];
  }
  
  
    int cutRod(int price[], int n) {
        //code here
        memset(T, 0, sizeof(T));
        int len[n];
        for(int i=0;i<n;i++) len[i]=i+1;
        return maxProfit(price, len, n, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends