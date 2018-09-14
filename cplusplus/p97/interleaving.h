//
// Created by testuser0 on 9/14/18.
//

#ifndef CPLUSPLUS_INTERLEAVING_H
#define CPLUSPLUS_INTERLEAVING_H

#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    bool *res;
    int rows;
    int cols;
    void setV(int pos_x, int pos_y, bool v ){
        res[pos_x*cols+pos_y] = v;
    }

    bool getV(int pos_x, int pos_y ){
        return res[pos_x*cols+pos_y];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if( s1.length() + s2.length() != s3.length() ) return false;
        rows = s1.length()+1;
        cols = s2.length()+1;
        res = new bool[sizeof(bool) * rows * cols ];
        memset( res, 0, sizeof(bool) * rows * cols );


        setV(0,0,true);
        for( int m = 1; m < rows; m ++ ){
            if( s1[m-1] == s3[m-1] && getV( m-1, 0 )){
                setV(m, 0, true);
            }
        }

        for( int n = 1; n < cols; n ++ ){
            if( s2[n-1] == s3[n-1] && getV(0, n-1) ){
                setV(0, n, true);
            }
        }

        for( int m = 1; m < rows; m ++ ){
            for (int n = 1; n < cols; ++n) {
                if( s1[m-1] == s3[m+n-1] ){
                    if( getV(m-1, n) ){
                        setV(m, n, true);
                        continue;
                    }
                }

                if( s2[n-1] == s3[m+n-1] ){
                    if( getV(m, n-1) ){
                        setV(m, n, true);
                    }
                }
            }
        }
        bool result = getV( rows-1, cols-1 );
        free(res);
        return result;
    }
};


#endif //CPLUSPLUS_INTERLEAVING_H
