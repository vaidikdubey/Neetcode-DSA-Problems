class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int num: nums) {
            map[num]++;
        }

        vector<pair<int, int>> updatedNums;

        for(auto &[num, freq]: map) {
            updatedNums.push_back({freq, num});
        }

        sort(updatedNums.begin(), updatedNums.end(), greater<pair<int, int>>());

        vector<int> result;

        for(int i = 0; k > 0 && i < updatedNums.size(); i++) {
            result.push_back(updatedNums[i].second);
            k--;
        }

        return result;
    }
};
