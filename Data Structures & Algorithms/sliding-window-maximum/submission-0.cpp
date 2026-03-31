class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        
        int i = 0, j = k;
        while(j <= n) {
            int maxVal = nums[i];
            for(int x = i; x < j; x++) {
                maxVal = max(maxVal, nums[x]);
            }

            result.push_back(maxVal);
            i++;
            j++;
        }

        return result;
    }
};
