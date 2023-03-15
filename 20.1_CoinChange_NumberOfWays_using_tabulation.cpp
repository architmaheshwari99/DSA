//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  

  
  long long calculate(int coins[], int N, int sum){
      
      long long int T[N+1][sum+1];  
      
    for(int j=0;j<=sum;j++){
        T[0][j]=0;
    } 
    
    for(int i=0;i<=N;i++){
        T[i][0]=1;
    }

        
      for(int i=1;i<=N;i++){
          for(int j=1;j<=sum;j++){
              if(j>=coins[i-1]){
                  T[i][j] = T[i-1][j] + T[i][j-coins[i-1]];
              } else{
                  T[i][j] = T[i-1][j];
              }
          }
      }

      return T[N][sum];

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