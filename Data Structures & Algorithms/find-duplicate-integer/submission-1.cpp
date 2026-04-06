class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) { //O(n)
            int idx = abs(nums[i]) - 1;

            //Duplicate value found, since value is already negative
            if(nums[idx] < 0) return abs(nums[i]);

            //Modify the value to negative to mark as visited
            else nums[idx] *= -1;
        }

        return -1; //T.C: O(n) | S.C: O(1)
    }
};
