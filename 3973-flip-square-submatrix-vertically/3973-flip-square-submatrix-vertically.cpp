class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Reverse rows within the submatrix
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }

        return grid;
    }
};
