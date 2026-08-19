class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0, end = numbers.size() - 1;

        vector<int> result(2, 0); //O(1)

        while(st < end) { //O(n)
            int currSum = numbers[st] + numbers[end];

            if(currSum == target) {
                result[0] = st + 1;
                result[1] = end + 1;

                break;
            }
            else if(currSum < target) st++;
            else end--;
        }

        return result; //T.C: O(n), S.C: O(1)
    }
};
