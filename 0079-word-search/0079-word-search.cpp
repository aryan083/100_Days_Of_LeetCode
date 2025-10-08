typedef vector<vector<char>> vvc;
typedef set<pair<int, int>> spii;
class Solution
{
public:
    bool dfs(int row, int col, int i,
             vvc &board, string &word, spii &paths)
    {
        int ROWS = board.size(), COLS = board[0].size();
        if (i == word.length())
            return true;
        if (row < 0 or col < 0 or row >= ROWS or col >= COLS or board[row][col] != word[i] or paths.count({row, col}))
            return false;

        paths.insert({row, col});

        bool ans = (dfs(row + 1, col, i + 1, board, word, paths) or
                    dfs(row - 1, col, i + 1, board, word, paths) or
                    dfs(row, col + 1, i + 1, board, word, paths) or
                    dfs(row, col - 1, i + 1, board, word, paths));

        paths.erase({row, col});
        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int ROWS = board.size(), COLS = board[0].size();

        unordered_map<char, int> boardFreq, wordFreq;
        for (auto &row : board)
            for (char ch : row)
                boardFreq[ch]++;
        for (char ch : word)
            wordFreq[ch]++;
        for (auto &[ch, count] : wordFreq)
            if (boardFreq[ch] < count)
                return false;

        spii paths;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (board[r][c] == word[0])
                {
                    if (dfs(r, c, 0, board, word, paths))
                        return true;
                }
            }
        }
        return false;
    }
};