class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s: string): number {
        const dupes = new Set<string>()
        let i = 0, j = 0, len = 0;

        while(j < s.length) {
            while(dupes.has(s[j])) {
                dupes.delete(s[i++])
            }

            len = Math.max(len, j - i + 1)

            dupes.add(s[j++])
        }

        return len
    }
}

