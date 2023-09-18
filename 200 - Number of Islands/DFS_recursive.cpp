class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        auto height = grid.size();
        auto width = grid[0].size();
        auto count{ 0 };

        for (std::size_t y = 0; y < height; ++y)
        {
            for (std::size_t x = 0; x < width; ++x)
            {
                if (grid[y][x] == '1')
                {
                    ++count;
                    eraseIsland(grid, x, y);
                }
            }
        }

        return count;
    }

    void eraseIsland(vector<vector<char>>& grid, int x, int y)
    {
        if (x >= 0 && y >= 0 && x < grid[0].size() && y < grid.size())
        {
            if (grid[y][x] == '1')
            {
                grid[y][x] = '0';
                eraseIsland(grid, x - 1, y);
                eraseIsland(grid, x, y - 1);
                eraseIsland(grid, x, y + 1);
                eraseIsland(grid, x + 1, y);
            }
        }
    }
};