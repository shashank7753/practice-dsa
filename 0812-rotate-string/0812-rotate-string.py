class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        if len(s) != len(goal):
            return False

        for _ in range(len(s)):
            if s == goal:
                return True
            s = s[1:] + s[0]  # Rotate `s` by moving the first character to the end
        return False