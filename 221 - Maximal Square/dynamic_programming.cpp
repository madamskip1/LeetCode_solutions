class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const auto ySize = matrix.size();
        const auto xSize = matrix[0].size();

        auto DP = std::vector<std::vector<int>>( ySize, std::vector<int>( xSize, 0 ) );
        auto maxSize = 0;

        // Fill first row
        for (std::size_t x = 0; x < xSize; ++x)
        {
            DP[0][x] = matrix[0][x] - '0';
            maxSize = std::max(maxSize, DP[0][x]);
        }

        // Fill first collumn
        for (std::size_t y = 0; y < ySize; ++y)
        {
            DP[y][0] = matrix[y][0] - '0';
            maxSize = std::max(maxSize, DP[y][0]);
        }

        const auto maxStartY = ySize - 1;
        const auto maxStartX = xSize - 1;

        for (std::size_t y = 1; y <= maxStartY; ++y)
        {
            const auto& row = DP[y];
            const auto& previousRow = DP[y - 1];

            for (std::size_t x = 1; x <= maxStartX; ++x)
            {
                if (matrix[y][x] != '0')
                {
                    auto minValueInSquare = std::min({previousRow[x - 1], previousRow[x], row[x - 1]});
                    DP[y][x] = minValueInSquare + (matrix[y][x] - '0');
                    maxSize = std::max(maxSize, DP[y][x]);
                }
            }
        }

        return maxSize * maxSize;
    }
};