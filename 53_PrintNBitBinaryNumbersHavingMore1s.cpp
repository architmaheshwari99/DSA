//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    void solve(vector<string> &ans, int N, string temp, int ones, int zeros){
        if(N==0){
            ans.push_back(temp);
            return;
        }
        
        solve(ans, N-1, temp+'1', ones+1, zeros);
        
        if(ones>zeros){
            solve(ans, N-1, temp+'0', ones, zeros+1);
        }
    }

	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> ans;
	    solve(ans, N, "", 0, 0);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends