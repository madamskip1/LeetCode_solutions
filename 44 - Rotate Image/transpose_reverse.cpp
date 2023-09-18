class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto rows = matrix.size();
        auto cols = matrix[0].size();

        auto startCol = std::size_t(1);

        for (std::size_t row = 0; row < rows; ++row)
        {
            for (std::size_t col = startCol; col < cols; ++col)
            {
                std::swap(matrix[row][col], matrix[col][row]);
            }

            ++startCol;
        }

        for (std::size_t row = 0; row < rows; ++row)
        {
            std::reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};