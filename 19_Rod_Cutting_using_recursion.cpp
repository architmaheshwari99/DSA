//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int maxProfit(int price[], int len[], int n, int maxLen){
      if(n==0) return 0;
      
      if(len[n-1]<=maxLen){
          return max(maxProfit(price, len, n-1, maxLen), price[n-1] + maxProfit(price, len, n, maxLen-len[n-1]));
      } else {
          return maxProfit(price, len, n-1, maxLen);
      }
  }
  
  
    int cutRod(int price[], int n) {
        //code here
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