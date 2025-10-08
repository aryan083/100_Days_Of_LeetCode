typedef vector<vector<char>> vvc;
typedef set<pair<int, int>> spii;
class Solution
{
public:
    bool dfs(int row, int col, int i, vvc &board, const string &word)
    {
        int ROWS = board.size(), COLS = board[0].size();
        if (i == word.length())
            return true;
        if (row < 0 || col < 0 || row >= ROWS || col >= COLS || board[row][col] != word[i])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = dfs(row + 1, col, i + 1, board, word) ||
                    dfs(row - 1, col, i + 1, board, word) ||
                    dfs(row, col + 1, i + 1, board, word) ||
                    dfs(row, col - 1, i + 1, board, word);

        board[row][col] = temp;
        return found;
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
                    if (dfs(r, c, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};