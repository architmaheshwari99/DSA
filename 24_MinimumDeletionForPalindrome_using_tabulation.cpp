//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string X, int n) { 
    //complete the function here 
    
            
        string Y = X;
        reverse(Y.begin(), Y.end());

        
        int T[n+1][n+1];
        memset(T, 0, sizeof(T));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1])
                    T[i][j] = 1+T[i-1][j-1];
                else{
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
                }
            }
        }
        
        return n-T[n][n];
    
    
} 