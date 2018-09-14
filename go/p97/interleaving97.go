package p97

func IsInterleave(s1 string, s2 string, s3 string) bool{
	return isInterleave(s1,s2,s3)
}

func isInterleave(s1 string, s2 string, s3 string) bool {
	if len(s1) + len(s2) != len(s3){
		return false
	}
	rows := len(s1) + 1
	cols := len(s2) + 1
	var res = make([][]bool, rows)
	for i :=0; i < rows; i++{
		res[i] = make( []bool, cols )
		for j := 0; j < cols; j ++ {
			res[i][j] = false
		}
	}

	res[0][0] = true

	for m := 1; m < rows; m ++{
		if s1[m-1] == s3[m-1] {
			res[m][0] = res[m-1][0]
		}
	}

	for n := 1; n < cols; n ++{
		if s2[n-1] == s3[n-1]{
			res[0][n] = res[0][n-1]
		}
	}

	for m := 1; m < rows; m ++ {
		for n := 1; n < cols ; n ++  {
			if s1[m-1] == s3[m+n-1]{
				res[m][n] = res[m-1][n]
				if res[m][n] {
					continue
				}
			}
			if s2[n-1] == s3[m+n-1]{
				res[m][n] = res[m][n-1]
				if res[m][n]{
					continue
				}

			}
		}
	}
	return res[rows-1][cols-1]
}
