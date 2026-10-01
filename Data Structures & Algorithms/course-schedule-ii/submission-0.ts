class Solution {
    /**
     * @param {number} numCourses
     * @param {number[][]} prerequisites
     * @return {number[]}
     */
    findOrder(numCourses: number, prerequisites: number[][]): number[] {
        const adj: number[][] = Array.from({length: numCourses}, () => [])
        const indegree: number[] = new Array(numCourses).fill(0)

        for(let [u, v] of prerequisites) {
            adj[v].push(u)
            indegree[u]++
        }

        const queue: number[] = []

        for(let i = 0; i < numCourses; i++) {
            if(indegree[i] === 0) queue.push(i)
        }

        const res: number[] = []
        let startPtr = 0;
        
        while(startPtr < queue.length) {
            let top = queue[startPtr++]
            res.push(top)

            for(let deps of adj[top]) {
                indegree[deps]--
                
                if(indegree[deps] === 0) queue.push(deps)
            }
        }

        return res.length === numCourses ? res : []
    }
}
