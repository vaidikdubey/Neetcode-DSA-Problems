class Solution {
    bool isValid(vector<vector<char>> &board, int row, int col, char curr) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == curr) return false;
        }

        for(int j = 0; j < 9; j++) {
            if(board[row][j] == curr) return false;
        }

        int stRow = 3 * (row / 3);
        int stCol = 3 * (col / 3);
        for(int i = stRow; i < stRow + 3; i++) {
            for(int j = stCol; j < stCol + 3; j++) {
                if(board[i][j] == curr) return false;
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) { //O(1)
            for(int col = 0; col < 9; col++) { //O(1)
                if(board[row][col] != '.') { //O(1)
                    char curr = board[row][col];
                    board[row][col] = '.';
                    if(!isValid(board, row, col, curr)) return false; //O(1)
                    board[row][col] = curr;
                }
            }
        }

        return true; //T.C: O(1), S.C: O(1) because sudoku is fixed 9x9
    }
};