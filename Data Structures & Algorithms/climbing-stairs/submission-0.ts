class Solution {
    /**
     * @param {number} n
     * @return {number}
     */
    climbStairs(n: number): number {
        const dfs = (i: number) => {
            if(i >= n) return i == n

            return dfs(i + 1) + dfs(i + 2)
        }

        return dfs(0);
    }
}
