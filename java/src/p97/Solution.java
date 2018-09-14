package p97;

public class Solution {
    boolean res[][];
    int rows;
    int cols;
    public boolean isInterleave(String s1, String s2, String s3) {
        if( s1.length() + s2.length() != s3.length() ){
            return false;
        }

        rows = s1.length() + 1;
        cols = s2.length() + 1;
        res = new boolean[rows][cols];
        for( int m = 0; m < rows; m ++ ){
            for (int n = 0; n < cols; n ++){
                res[m][n] = false;
            }
        }

        res[0][0] = true;

        for( int m = 1; m < rows; m ++ ){
            if( s1.charAt(m-1) == s3.charAt(m-1)){
                res[m][0] = res[m-1][0];
            }
        }

        for( int n = 1; n < cols; n ++){
            if( s2.charAt(n-1) == s3.charAt(n-1)){
                res[0][n] = res[0][n-1];
            }
        }

        for( int m = 1; m < rows; m ++ ){
            for (int n = 1; n < cols; n ++){
                if( s1.charAt(m-1) == s3.charAt(m+n-1) ){
                    if( res[m-1][n] ){
                        res[m][n] = true;
                        continue;
                    }
                }
                if( s2.charAt(n-1) == s3.charAt(m+n-1)){
                    if( res[m][n-1] ){
                        res[m][n] = true;
                    }
                }
            }
        }

        return res[rows-1][cols-1];
    }
}