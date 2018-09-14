package p97

import (
	"testing")


func TestIsInterleave1(t *testing.T)  {
	s1 := "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	s2 := "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	s3 := "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";

	if !IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}

func TestIsInterleave2(t *testing.T)  {
	s1 := "aabcc"
	s2 := "dbbca"
	s3 := "aadbbcbcac"
	if IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}

func TestIsInterleave3(t *testing.T)  {
	s1 := "aabcc"
	s2 := "dbbca"
	s3 := "aadbbbaccc"
	if !IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}

func TestIsInterleave4(t *testing.T)  {
	s1 := "ace"
	s2 := "bdf"
	s3 := "abdcef"
	if IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}

func TestIsInterleave5(t *testing.T)  {
	s1 := "aabaac"
	s2 := "aadaaeaaf"
	s3 := "aadaaeaabaacaaf"
	if IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}

func TestIsInterleave6(t *testing.T)  {
	s1 := "bab"
	s2 := "abbbcba"
	s3 := "babbbabcba"
	if IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}

func TestIsInterleave7(t *testing.T)  {
	s1 := "aa"
	s2 := "ab"
	s3 := "aaba"
	if IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}

func TestIsInterleave8(t *testing.T)  {
	s1 := ""
	s2 := ""
	s3 := ""
	if IsInterleave(s1,s2,s3){
		t.Log("pass")
	}else {
		t.Error("failed")
	}
}