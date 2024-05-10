class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0
        for i in range(len(columnTitle)):
            letter_value = ord(columnTitle[i]) - ord('A') + 1
            position = len(columnTitle) - i - 1
            result += letter_value * (26 ** position)
        return result