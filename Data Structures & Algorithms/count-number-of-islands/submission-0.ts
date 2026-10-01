class Solution {
    /**
     * @param {character[][]} grid
     * @return {number}
     */
    findIslands(
        i: number,
        j: number,
        grid: string[][],
        vis: boolean[][],
        row: number,
        col: number,
    ): void {
        if (i < 0 || i >= row || j < 0 || j >= col) return;
        if (grid[i][j] !== "1" || vis[i][j]) return;

        vis[i][j] = true;

        this.findIslands(i + 1, j, grid, vis, row, col);
        this.findIslands(i - 1, j, grid, vis, row, col);
        this.findIslands(i, j + 1, grid, vis, row, col);
        this.findIslands(i, j - 1, grid, vis, row, col);
    }

    numIslands(grid: string[][]): number {
        let count = 0;

        let n = grid.length,
            m = grid[0].length;

        const visited: boolean[][] = Array.from({ length: n }, () => Array(m).fill(false));

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (grid[i][j] === "1" && !visited[i][j]) {
                    this.findIslands(i, j, grid, visited, n, m);
                    count++;
                }
            }
        }

        return count;
    }
}
