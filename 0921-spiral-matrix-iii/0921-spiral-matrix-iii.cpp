class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res(rows*cols);
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int r = rStart;
        int c = cStart;
        int j = 0;
        int curr_dir = 0;
        int steps = 1;

        while(j < rows*cols){
            for(int i=0; i<2; i++){
                int r_delta = directions[curr_dir][0];
                int c_delta = directions[curr_dir][1];
                for(int step=0; step<steps; step++){
                    if(0 <= r && r < rows && 0 <= c && c < cols)
                        res[j++] = {r, c};
                    r = r + r_delta;
                    c = c + c_delta;
                }
                curr_dir = (curr_dir+1)%4;
            }
            steps++;
        }
        return res;
    }
};