class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums: number[], target: number): number[] {
        const map = new Map<number, number>()

        for(let i = 0; i < nums.length; i++) {
            const newTgt = target - nums[i]
            if(map.has(newTgt)) {
                const j = map.get(newTgt);
                
                return i < j ? [i, j] : [j, i]
            }
            else map.set(nums[i], i)
        }
        return Array(2).fill(0)
    }
}
