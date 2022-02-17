class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        a = [""] * 26
        word = s.split()
        s = len(pattern)
        if s != len(word):
            return False
        
        for i in range(0, len(word)):
            if a[ord(pattern[i%s])-97] == "":
                a[ord(pattern[i%s])-97] = word[i]
                if a.count(word[i]) > 1:
                    return False
            elif a[ord(pattern[i%s])-97] != word[i]:
                return False
            
        return True
