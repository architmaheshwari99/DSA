class Solution {
public:

    void findSol(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int target, int idx){
        if(target<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;

            temp.push_back(arr[i]);
            findSol(ans, arr, temp, target-arr[i], i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        findSol(ans, candidates, temp, target, 0);

        return ans;


    }
};