//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    int T[n+1][n+1];
		    memset(T, 0 , sizeof(T));
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(str[i-1]==str[j-1] && i!=j)
		                T[i][j] = 1 + T[i-1][j-1];
		            else
		                T[i][j] = max(T[i-1][j], T[i][j-1]);
		        }
		    }
		    return T[n][n];
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends