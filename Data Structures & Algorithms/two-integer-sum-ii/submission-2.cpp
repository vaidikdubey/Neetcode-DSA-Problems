class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i < n; i++) {
            int updatedTgt = target - numbers[i];

            int lo = i + 1, hi = n - 1;

            while(lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if(numbers[mid] == updatedTgt)return {i+1, mid+1};
                else if(numbers[mid] < updatedTgt) lo = mid + 1;
                else hi = mid - 1;
            }
        }

        return {0, 0};
    }
};
