//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int calculate(int coins[], int N, int sum){
      if(sum==0) return 1;
      if(N==0) return 0;
      
      if(coins[N-1]<=sum){
          return calculate(coins, N-1, sum) + calculate(coins, N, sum-coins[N-1]);
      } else {
          return calculate(coins, N-1, sum);
      }
      
      
  }
  
  
    long long int count(int coins[], int N, int sum) {
        return calculate(coins, N, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends