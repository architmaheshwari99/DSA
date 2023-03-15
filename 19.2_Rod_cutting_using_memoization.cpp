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
      if(n==0) return 0;
      if(T[n][maxLen]!=-1) return T[n][maxLen];
      if(len[n-1]<=maxLen){
          return T[n][maxLen] = max(maxProfit(price, len, n-1, maxLen), price[n-1] + maxProfit(price, len, n, maxLen-len[n-1]));
      } else {
          return T[n][maxLen] = maxProfit(price, len, n-1, maxLen);
      }
  }
  
  
    int cutRod(int price[], int n) {
        //code here
        memset(T, -1, sizeof(T));
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