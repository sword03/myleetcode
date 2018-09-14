//
// Created by testuser0 on 9/13/18.
//

#ifndef LEETCODE_M2_INTERLEAVINGSTRING_H
#define LEETCODE_M2_INTERLEAVINGSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/time.h>

bool getV(unsigned char* v, int Rows, int Cols, int row, int col ){
    char r = v[ row * Cols + col ];
    if( r ) return true;
    return false;
}

void setV( unsigned char* v, int Rows, int Cols, int row, int col , bool b ){
    if( b  ){
        v[ row * Cols + col ] = 1;
    } else{
        v[ row * Cols + col ] = 0;
    }
}


bool isInterleave(char* s1, char* s2, char* s3) {
    int pathLen = 0;
    if( strlen(s1) + strlen(s2) != strlen(s3) ) return false;
    unsigned char * v = calloc( 1, sizeof(unsigned char) * (strlen(s1)+1) * (strlen(s2)+1) );
    int Rows = strlen(s1) + 1;
    int Cols = strlen(s2) + 1;

    setV(v, Rows, Cols, 0, 0, 1);
    for( int m = 1; m < Rows; ++m ){
        if( s1[m-1] == s3[m-1] && getV(v, Rows, Cols, m-1, 0) ){
            setV(v, Rows, Cols, m, 0, 1);
        } else{
            setV(v, Rows, Cols, m, 0, 0);
        }
    }

    for (int n = 1; n < Cols ; ++n) {
        if( s2[n-1] == s3[n-1] && getV(v, Rows, Cols, 0, n-1) ){
            setV(v, Rows, Cols, 0, n, 1);
        } else{
            setV(v, Rows, Cols, 0, n, 0);
        }
    }


    for( int m = 1; m < Rows; ++m ){
        for (int n = 1; n < Cols ; ++n) {
            if( s1[m-1] == s3[m+n-1] ){
                if( getV(v, Rows, Cols, m-1, n) ){
                    setV(v, Rows, Cols, m, n, 1);
                    continue;
                } else{
                    setV(v, Rows, Cols, m, n, 0);
                }
            }

            if( s2[n-1] == s3[m+n-1] ){
                if( getV(v, Rows, Cols, m, n-1) ){
                    setV(v, Rows, Cols, m, n, 1);
                    continue;
                } else{
                    setV(v, Rows, Cols, m, n, 0);
                }
            }
        }
    }
    
    return getV(v, Rows, Cols, Rows-1, Cols-1);
}

void test_interleavingString97(){
    struct timeval t1, t2;
    int64_t elapsedTime;

    // start timer
    gettimeofday(&t1, NULL);

    char* s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    char* s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    char* s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    //printf( "p97:%s\n", isInterleave(s1, s2, s3 )?"true":"false" );
    isInterleave(s1, s2, s3 );
    gettimeofday(&t2, NULL);

    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000.0 ;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) ;   // us to ms
    printf("time cost: %zd us\n", elapsedTime);

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    printf( "p97:%s\n", isInterleave(s1, s2, s3 )?"true":"false" );

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbbaccc";
    printf( "p97:%s\n", isInterleave(s1, s2, s3 )?"true":"false" );

    s1 = "ace";
    s2 = "bdf";
    s3 = "abdcef";
    printf( "p97:%s\n", isInterleave(s1, s2, s3 )?"true":"false" );

    s1 = "aabaac";
    s2 = "aadaaeaaf";
    s3 = "aadaaeaabaacaaf";
    printf( "p97:%s\n", isInterleave(s1, s2, s3 )?"true":"false" );

    s1 = "bab";
    s2 = "abbbcba";
    s3 = "babbbabcba";
    printf( "p97:%s\n", isInterleave(s1, s2, s3 )?"true":"false" );

    s1 = "aa";
    s2 = "ab";
    s3 = "aaba";
    printf( "p97:%s\n", isInterleave(s1, s2, s3 )?"true":"false" );
}
#endif //LEETCODE_M2_INTERLEAVINGSTRING_H
