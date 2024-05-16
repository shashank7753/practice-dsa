class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        minSubSequence = []
        
        nums.sort(reverse=True)
        
        totalSum = sum(nums)
        
        currentSum = 0
        
        for num in nums:
            totalSum -= num  
            currentSum += num  
            minSubSequence.append(num)  
            if currentSum > totalSum:
                return minSubSequence 
        return minSubSequence  