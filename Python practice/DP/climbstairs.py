class Solution:
    def climbStairs(self, n: int) -> int:
        d = {};
        d[1] = 1;
        d[2] = 2;
        if n in d.keys():
            return d[n];
        for i in range(3, n+1):
            d[i] = d[i-1] + d[i-2];
        return d[n];
        