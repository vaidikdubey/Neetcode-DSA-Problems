class Solution {
    int findPivot(vector<int> & nums) { //O(logn)
        int lo = 0, hi = nums.size() - 1;

        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }

        return hi;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums); //O(logn)

        //If array is rotated
        if(pivot > 0) {
            //Binary search on 0 - pivot segment
            int lo = 0, hi = pivot - 1;

            while(lo <= hi) { //O(logn)
                int mid = lo + (hi - lo) / 2;

                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        
        int lo = pivot, hi = nums.size() - 1;
        //Binary search on pivot - n segment
        while(lo <= hi) { //O(logn)
                int mid = lo + (hi - lo) / 2;

                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) lo = mid + 1;
                else hi = mid - 1;
        }

        return -1; //T.C: O(logn), S.C: O(1)
    }
};
