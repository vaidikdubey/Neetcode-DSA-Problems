class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row = matrix.size();
       int col = matrix[0].size();

       if((target > matrix[row - 1][col - 1]) || (target < matrix[0][0]))
        return false;

       int lo = 0, hi = row * col - 1;

       while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        int ele = matrix[mid/col][mid%col];

        if(ele == target) return true;
        else if(ele < target) lo = mid + 1;
        else hi = mid - 1;
       }

       return false;
    }
};
