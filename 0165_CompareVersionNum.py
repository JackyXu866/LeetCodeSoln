class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split(".")
        v2 = version2.split(".")
        
        s = max(len(v1), len(v2))
        
        for i in range(s):
            if i < len(v1):
                i1 = int(v1[i])
            else:
                i1 = 0
            if i < len(v2):
                i2 = int(v2[i])
            else:
                i2 = 0
            
            if i1 < i2:
                return -1
            elif i1 > i2:
                return 1
            
        return 0
