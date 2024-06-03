class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        i, j = 0, 0  
        
        while i < len(s) and j < len(t):  
            if s[i] == t[j]: 
                j += 1  
            i += 1  # Always move the pointer in s forward
        
        return len(t) - j  # The number of characters in t not matched in s
               