class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        auto isMagicSquare = [&](int r, int c) -> bool {
            vector<int> vals(10, 0);
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int num = grid[r + i][c + j];
                    if (num < 1 || num > 9 || vals[num]) return false;
                    vals[num] = 1;
                }
            }
            return (grid[r][c] + grid[r][c+1] + grid[r][c+2] == 15 &&
                    grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] == 15 &&
                    grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] == 15 &&
                    grid[r][c] + grid[r+1][c] + grid[r+2][c] == 15 &&
                    grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] == 15 &&
                    grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] == 15 &&
                    grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] == 15 &&
                    grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] == 15);
        };

        for (int i = 0; i < rows - 2; ++i) {
            for (int j = 0; j < cols - 2; ++j) {
                if (isMagicSquare(i, j)) {
                    ++count;
                }
            }
        }

        return count;
    }
};