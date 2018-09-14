import unittest
from .Interleaving97 import Solution
class TestInterleaving97(unittest.TestCase):

    def test_isInterleaving97(self):
        sol = Solution()
        self.assertTrue(sol.isInterleave("ab", "aa", "aaba"))
        self.assertTrue(sol.isInterleave("aabcc", "dbbca","aadbbcbcac"))
        self.assertFalse(sol.isInterleave("aabcc", "dbbca","aadbbbaccc"))
        self.assertTrue(sol.isInterleave("ace", "bdf", "abdcef"))
        self.assertTrue(sol.isInterleave("aabaac","aadaaeaaf","aadaaeaabaacaaf"))
        self.assertTrue(sol.isInterleave("bab", "abbbcba", "babbbabcba"))
        self.assertFalse(sol.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
                                         "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
                                         "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"))

if __name__ == '__main__':
    unittest.main()
