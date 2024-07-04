class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        s1 = set(list1)
        s2 = set(list2)
        s3 = s1 - s2
        temp = list(s1 - s3)
        n = len(temp)
        count = [0]*n
        for it in range(n):
            word = temp[it]
            a = list1.index(word)
            b = list2.index(word)
            count[it] += a+b
        m = min(count)
        res = []
        for it in range(n):
            word = temp[it]
            if count[it]==m:
                res.append(word)
        return res