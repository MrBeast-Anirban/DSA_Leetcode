class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        R, C = len(grid), len(grid[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def dfs(r, c):
            if r<0 or r>=R or c<0 or c>=C: return
            if grid[r][c] != '1': return
            grid[r][c] = '#' # mark the node visited inplace
            for dr, dc in directions:
                dfs(r+dr, c+dc)
        count = 0
        for r in range(R):
            for c in range(C):
                if grid[r][c] == '1':
                    dfs(r, c)
                    count += 1
        return count
