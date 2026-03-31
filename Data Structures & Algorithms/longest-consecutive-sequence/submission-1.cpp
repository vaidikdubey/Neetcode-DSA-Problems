class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxLen = 0, curr = nums[0], len = 0, i = 0;

        while(i < nums.size()) {
            if(curr != nums[i]) {
                curr = nums[i];
                len = 0;
            }

            while(i < nums.size() && curr == nums[i]) {
                i++;
            }
            len++;
            curr++;
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};
