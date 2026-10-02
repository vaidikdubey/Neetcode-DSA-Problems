class Solution {
    /**
     * @param {character[][]} grid
     * @return {number}
     */
    numIslands(grid: string[][]): number {
        if (!grid || grid.length === 0) return 0;

        const n = grid.length,
            m = grid[0].length;
        let count = 0;

        const directions: [number, number][] = [
            [-1, 0], // Up
            [1, 0], // Down
            [0, -1], // Left
            [0, 1], // Right
        ];

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (grid[i][j] === "1") {
                    count++;

                    grid[i][j] = "0";

                    const queue: [number, number][] = [[i, j]];
                    let head = 0;

                    while (head < queue.length) {
                        const [currR, currC] = queue[head++];

                        for (let [dr, dc] of directions) {
                            const newR = currR + dr;
                            const newC = currC + dc;

                            if (
                                newR >= 0 &&
                                newR < n &&
                                newC >= 0 &&
                                newC < m &&
                                grid[newR][newC] === "1"
                            ) {
                                grid[newR][newC] = "0";
                                queue.push([newR, newC]);
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
}
