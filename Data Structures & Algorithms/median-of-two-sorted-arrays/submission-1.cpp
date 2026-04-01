class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int total = A.size() + B.size();
        int half = (total + 1) / 2; //This ensures in case of odd, median is in left

        if(B.size() < A.size()) {
            swap(A, B);
        }

        int lo = 0, hi = A.size();
        //Binary search to find correct partition, O(log (m + n))
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int rem = half - mid;

            int ALeft = mid > 0 ? A[mid - 1] : INT_MIN;
            int ARight = mid < A.size() ? A[mid] : INT_MAX;
            int BLeft = rem > 0 ? B[rem - 1] : INT_MIN;
            int BRight = rem < B.size() ? B[rem] : INT_MAX;

            //If partition is correct return result
            if(ALeft <= BRight && BLeft <= ARight) {
                //Odd case
                if(total % 2 != 0) return max(ALeft, BLeft);
                else return (max(ALeft, BLeft) + min(ARight, BRight)) / 2.0;
            }
            else if(ALeft > BRight) hi = mid - 1;
            else lo = mid + 1;
        }

        return -1;
    }
};
