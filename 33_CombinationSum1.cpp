class Solution {
public:

    void findComb(int idx, vector<vector<int>> &res, 
                        vector<int> candidates, 
                        vector<int> &temp, 
                        int target){

        if(idx==candidates.size() || target<0){
            return;
        }
        if(target==0){
            res.push_back(temp);
            return;
        }

        temp.push_back(candidates[idx]);
        findComb(idx, res, candidates, temp, target-candidates[idx]);
        temp.pop_back();

        findComb(idx+1, res, candidates, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findComb(0, ans, candidates, temp, target);
        return ans;
    }
};