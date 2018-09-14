class Solution(object):
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3) :
            return False

        self.rows = len(s1) + 1
        self.cols = len(s2) + 1
        self.table = [[False for i in range(self.cols)] for j in range(self.rows)]

        self.table[0][0] = True

        for m in range(1, self.rows):
            if s1[m-1] == s3[m-1]:
                self.table[m][0] = self.table[m-1][0]

        for n in range(1, self.cols):
            if s2[n-1] == s3[n-1]:
                self.table[0][n] = self.table[0][n-1]

        for m in range(1, self.rows):
            for n in range(1, self.cols):
                if s1[m-1] == s3[m+n-1]:
                    self.table[m][n] |= self.table[m-1][n]

                if s2[n-1] == s3[m+n-1]:
                    self.table[m][n] |= self.table[m][n-1]


        return self.table[ self.rows-1][ self.cols-1]

