class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort the candidates
        vector<vector<int>> ans;
        vector<int> elem;
        int n = candidates.size();

        function<void(int, int)> backtrack = [&](int idx, int curr_sum) {
            if (curr_sum == target) {
                ans.push_back(elem);  
                return;
            }
            
            if (idx == n || curr_sum > target) {
                return; 
            }
            
            elem.push_back(candidates[idx]);  
            backtrack(idx + 1, curr_sum + candidates[idx]);
            elem.pop_back();  
            
            while (idx + 1 < n && candidates[idx] == candidates[idx + 1]) {
                idx++;
            }
            backtrack(idx + 1, curr_sum);  
        };
           
        
        backtrack(0, 0);
        return ans;
    }
};