class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        arr,res,total,size=[],[],0,len(words)
        for i in range(size):
            if total+len(words[i])+len(arr)<=maxWidth:
                total+=(len(words[i]))
                arr.append(words[i])
                if i==size-1:
                    line=""
                    for j in range(len(arr)):
                        line+=arr[j]
                        if j!=len(arr)-1:line+=" "
                    line+=" "*(maxWidth-len(line))
                    res.append(line)
            else:
                line=""
                arrSize=len(arr)
                spaces=maxWidth-total
                if arrSize==1:line=arr[0]+" "*spaces
                else:
                    space1=int(spaces/(arrSize-1))
                    spaceX=spaces%(arrSize-1)
                    for j in range(arrSize):
                        if j!=arrSize-1:
                            line+=arr[j]
                            if j<spaceX:line+=" "*(space1+1)
                            else :line+=" "*(space1)
                        else:line+=arr[j]
                res.append(line)
                line=""
                arr=[words[i]]
                total=len(words[i])
                if i==size-1:
                    line=arr[0]+" "*(maxWidth-len(arr[0]))
                    res.append(line)
        return res
    