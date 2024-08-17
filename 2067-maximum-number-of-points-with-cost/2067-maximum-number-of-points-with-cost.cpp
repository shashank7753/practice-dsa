class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
       
        int rows = points.size();
        int cols = points[0].size();
        vector<long long> prevRow(cols, 0);
        for(int i = 0 ; i < cols ; i++){
            prevRow[i] = points[0][i];
        }
        for(int row = 0 ; row < rows - 1; row++){
            vector<long long> leftMax(cols, 0);
            vector<long long> rightMax(cols, 0);
            vector<long long> currRow(cols, 0);
            leftMax[0] = prevRow[0];
            for(int col = 1 ; col < cols ; col++){
                leftMax[col] = max(leftMax[col - 1] - 1, prevRow[col]);
            }
            rightMax[cols - 1] = prevRow[cols - 1];
            for(int col = cols - 2 ; col >= 0 ; col--){
                rightMax[col] = max(rightMax[col + 1] - 1, prevRow[col]);
            }
            for(int col = 0 ; col < cols ; col++){
                currRow[col] = max(leftMax[col], rightMax[col]) + points[row + 1][col];
            }
            prevRow = currRow;
        }
        long long ans = LONG_LONG_MIN;
        for(int i = 0 ; i < cols ; i++){
            ans = max(ans, prevRow[i]);
        }
        return ans;
    }
};