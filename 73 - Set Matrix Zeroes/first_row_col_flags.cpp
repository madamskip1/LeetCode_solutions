class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        auto hasFirstRowZero{ false };
        auto hasFirstColZero{ false };
        auto rows = matrix.size();
        auto cols = matrix[0].size();

        for (std::size_t row = 0; row < rows; ++row)
        {
            if (matrix[row][0] == 0)
            {
                hasFirstColZero = true;
                break;
            }
        }

        for (std::size_t col = 0; col < cols; ++col)
        {
            if (matrix[0][col] == 0)
            {
                hasFirstRowZero = true;
                break;
            }
        }

        for (std::size_t row = 1; row < rows; ++row)
        {
            for (std::size_t col = 1; col < cols; ++col)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (std::size_t row = 1; row < rows; ++row)
        {
            for (std::size_t col = 1; col < cols; ++col)
            {
                if (matrix[0][col] == 0 || matrix[row][0] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        if (hasFirstRowZero)
        {
            for (std::size_t col = 0; col < cols; ++col)
            {
                matrix[0][col] = 0;
            }
        }

        if (hasFirstColZero)
        {
            for (std::size_t row = 0; row < rows; ++row)
            {
                matrix[row][0] = 0;
            }
        }
    }
};