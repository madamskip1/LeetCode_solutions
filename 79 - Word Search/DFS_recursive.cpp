class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        auto rows = board.size();
        auto cols = board[0].size();
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                auto wordExist = DFS(col, row, 0, board, word);
                if (wordExist)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool DFS(int x, int y, int wordIndex,
        std::vector<std::vector<char>>& board, const std::string& word)
    {
        if (x < 0 ||
            y < 0 ||
            x >= board[0].size() ||
            y >= board.size())
        {
            return false;
        }
        if (board[y][x] == '0')
        {
            return false;
        }
        if (board[y][x] != word[wordIndex])
        {
            return false;
        }
        ++wordIndex;
        if (wordIndex >= word.length())
        {
            return true;
        }

        auto charBefore = board[y][x];
        board[y][x] = '0';
        auto wordExist = (
            DFS(x + 1, y, wordIndex, board, word) ||
            DFS(x, y + 1, wordIndex, board, word) ||
            DFS(x - 1, y, wordIndex, board, word) ||
            DFS(x, y - 1, wordIndex, board, word)
            );
        board[y][x] = charBefore;
        return wordExist;
    }
};