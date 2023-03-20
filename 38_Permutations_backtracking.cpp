//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void find(string &S, vector<string> &ans, int l){
	        if(l==S.size()){
	            ans.push_back(S);
	            return;
	        }
	        
	        for(int i=l;i<S.size();i++){
	            swap(S[l], S[i]);
	            find(S, ans, l+1);
	            swap(S[l], S[i]);
	        }
	        
	        
	    }
	
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    
		    vector<string> ans;
		    find(S, ans, 0);
		    set<string> s(ans.begin(), ans.end());
		    return vector<string> (s.begin(), s.end());
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends