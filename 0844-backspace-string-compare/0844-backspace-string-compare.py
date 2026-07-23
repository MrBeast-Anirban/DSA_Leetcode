class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_new, t_new = "", ""
        count = 0
        for i in range (len(s)-1, -1, -1):
            if s[i] == '#':
                count += 1
            else:
                if count == 0:
                    s_new = s[i] + s_new
                else:
                    count -= 1
        count = 0
        for i in range (len(t)-1, -1, -1):
            if t[i] == '#':
                count += 1
            else:
                if count == 0:
                    t_new = t[i] + t_new
                else:
                    count -= 1
        return s_new == t_new


        