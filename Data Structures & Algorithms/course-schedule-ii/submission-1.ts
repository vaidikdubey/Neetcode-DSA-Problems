class Solution {
    /**
     * @param {number} numCourses
     * @param {number[][]} prerequisites
     * @return {number[]}
     */
    findOrder(numCourses: number, prerequisites: number[][]): number[] {
        const adjList: number[][] = Array.from({length: numCourses}, () => [])
        const indegree: number[] = new Array(numCourses).fill(0)

        for(let [prereq, course] of prerequisites) {
            adjList[course].push(prereq)
            indegree[prereq]++
        }

        const queue: number[] = []
        for(let i = 0; i < numCourses; i++) {
            if(indegree[i] === 0) queue.push(i)
        }

        const orderedCourses: number[] = []
        let ptr = 0;

        while(ptr < queue.length) {
            const course = queue[ptr++]
            orderedCourses.push(course)

            for(let dep of adjList[course]) {
                indegree[dep]--

                if(indegree[dep] === 0) queue.push(dep)
            }
        }

        return orderedCourses.length === numCourses ? orderedCourses : []
    }
}
