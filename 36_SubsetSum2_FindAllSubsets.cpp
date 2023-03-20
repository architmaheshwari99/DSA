//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void findSubset(vector<int> &A, vector<vector<int>> &vec, vector<int> &temp, int idx){
        if(idx==A.size()){
            vec.push_back(temp);
            return;
        }
        
        findSubset(A, vec, temp, idx+1);
        
        temp.push_back(A[idx]);
        findSubset(A, vec, temp, idx+1);
        temp.pop_back();
    }
    
    
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> vec;
        vector<int> temp;
        // reverse(A.begin(), A.end());
        findSubset(A, vec, temp, 0);
        
        sort(vec.begin(), vec.end());
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends