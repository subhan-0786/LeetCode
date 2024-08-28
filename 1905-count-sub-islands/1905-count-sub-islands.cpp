
class Solution {
public:
    int m, n;
    
    bool dfs(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2, int i, int j) {
        // Boundary checks
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)
            return true;
        
        // Mark the current cell as visited
        grid2[i][j] = 0;
        
        // Check if the corresponding cell in grid1 is land
        bool isSubIsland = grid1[i][j] == 1;
        
        // Explore all 4 directions
        bool up = dfs(grid1, grid2, i - 1, j);
        bool down = dfs(grid1, grid2, i + 1, j);
        bool left = dfs(grid1, grid2, i, j - 1);
        bool right = dfs(grid1, grid2, i, j + 1);
        
        // The current island is a sub-island only if all parts are sub-islands
        return isSubIsland && up && down && left && right;
    }
    
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        m = grid2.size();
        n = grid2[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j))
                        ++count;
                }
            }
        }
        
        return count;
    }
};
