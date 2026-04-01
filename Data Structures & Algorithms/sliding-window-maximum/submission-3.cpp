class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        priority_queue<pair<int, int>> pq; //<element, index> //n size

        vector<int> result;

        //Processing first window (0 - k-1 loop)
        for(i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        result.push_back(pq.top().first);

        while(i < n) { //(k - n-1 loop)
            pq.push({nums[i], i});

            //Removing elements with index less that lower limit of current window
            while(!pq.empty() && pq.top().second < i - k + 1) {
                pq.pop();
            }

            if(!pq.empty()) {
                result.push_back(pq.top().first);
            }

            i++;
        }

        return result; //T.C: O(n), S.C: O(n)
    }
};
