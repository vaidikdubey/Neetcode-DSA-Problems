class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rem;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int newTgt = target - nums[i];
            if(rem.find(newTgt) != rem.end()) {
                vector<int> arr(2);

                if(i < rem[newTgt]) {
                    arr[0] = i;
                    arr[1] = rem[newTgt];
                }
                else {
                    arr[0] = rem[newTgt];
                    arr[1] = i;
                }

                return arr;
            }
            else {
                rem[nums[i]] = i;
            }
        }

        return {};
    }
};
