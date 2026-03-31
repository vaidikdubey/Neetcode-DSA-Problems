class Solution {
    bool isValid(vector<vector<char>> &board, int row, int col, char num) {
        //Check row for duplicates
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == num) return false;
        }

        //Check col for duplicates
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num) return false;
        }

        //Check 3x3 grid for duplicates
        int stRow = 3 * (row / 3);
        int stCol = 3 * (col / 3);
        for(int i = stRow; i < stRow + 3; i++) {
            for(int j = stCol; j < stCol + 3; j++) {
                if(board[i][j] == num) return false;
            }
        }

        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    char num = board[i][j];
                    board[i][j] = '.';
                    if(!isValid(board, i, j, num)) return false;
                    board[i][j] = num;
                }
            }
        }

        return true;
    }
};
