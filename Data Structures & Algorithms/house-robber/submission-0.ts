class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    rob(nums: number[]): number {
        let beforePrev = 0;
        let prev = 0;

        for (let i = 0; i < nums.length; i++) {
            const curr = Math.max(nums[i] + beforePrev, prev);
            beforePrev = prev;
            prev = curr;
        }

        return prev;
    }
}
