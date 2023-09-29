class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle)
        : rectangle(rectangle)
    {
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (auto row = row1; row <= row2; ++row)
        {
            for (auto col = col1; col <= col2; ++col)
            {
                rectangle[row][col] = newValue;
            }
        }
    }

    int getValue(int row, int col) {
        return rectangle[row][col];
    }

private:
    std::vector<std::vector<int>>& rectangle;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */