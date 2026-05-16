class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while(lo <= hi) { //Single Binary Search Loop: O(logn)
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] == target) return mid;
            
            if(nums[lo] <= nums[mid]) { //Segment Check (low <-> mid)
                if(target > nums[mid] || target < nums[lo]) { //No: Change segment
                    lo = mid + 1;
                }
                else { //Yes: Update segment
                    hi = mid - 1;
                }
            }
            //Segment Check (mid <-> high)
            else { //nums[hi] >= nums[mid]
                if(target < nums[mid] || target > nums[hi]) { //No: Change segment
                    hi = mid - 1;
                }
                else { //Yes: Update segment
                    lo = mid + 1;
                }
            }
        }

        return -1; //T.C: O(logn), S.C: O(1)
    }
};
