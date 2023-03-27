//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    
    void solve(vector<int> &vec, int n, int k, int idx){
        if(vec.size()==1){
            return;
        }
        
        int next_kill = (idx+k-1)%vec.size();

        vec.erase(vec.begin()+next_kill, vec.begin()+next_kill+1);

        
        solve(vec, n, k, next_kill);
        
    }
    
    
    
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> vec;
       for(int i=1;i<=n;i++){
           vec.push_back(i);
       }
       
      solve(vec, n, k, 0);
       return vec[0];
       
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends