class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        odds_so_far = 0

        for num in arr:
            if num & 1 == 1:
                odds_so_far += 1
                if odds_so_far == 3:
                    return True
            else:
                odds_so_far = 0
        return False