//
// Created by testuser0 on 9/13/18.
//

#ifndef LEETCODE_M1_INTERLEAVINGSTRING_H
#define LEETCODE_M1_INTERLEAVINGSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/time.h>

bool alreadyCached(unsigned char* v, int Rows, int Cols, int row, int col ){
    char r = v[ row * Cols + col ];
    assert( r == 0 || r == 100 || r == 101 );
    return r != 0;
}


bool hasFound(unsigned char* v, int Rows, int Cols, int row, int col ){
    char r = v[ row * Cols + col ];
    if( r == 101 ){
        return true;
    }
    assert( r == 100 );
    return false;
}

void  setFoundState( unsigned char* v, int Rows, int Cols, int row, int col , bool b ){
    if( b  ){
        v[ row * Cols + col ] = 101;
    }
    v[ row * Cols + col ] = 100;
}

bool find(char* s1, char* s2, char* s3, int pathLen, int pos1,int pos2, char * v ){
    bool found = false;

    if( pathLen == strlen(s3) ) {
        found = true;
    }

    if( !found && pos1 < strlen(s1) ){
        if( s1[pos1] == s3[pathLen]){
            pathLen++;
            pos1++;
            if(alreadyCached(v, strlen(s1)+1, strlen(s2)+1, pos1, pos2)){
                if( hasFound(v, strlen(s1)+1, strlen(s2)+1, pos1, pos2) ) {
                    found = true;
                }
            } else{
                if( find(s1, s2 , s3 ,pathLen,pos1, pos2, v) ) {
                    found = true;
                }
            }

            pathLen--;
            pos1--;
        }
    }

    if( !found && pos2 < strlen(s2) ){
        if( s2[pos2] == s3[pathLen]){
            pathLen++;
            pos2++;

            if(alreadyCached(v, strlen(s1)+1, strlen(s2)+1, pos1, pos2)){
                if( hasFound(v, strlen(s1)+1, strlen(s2)+1, pos1, pos2) ) {
                    found = true;
                }
            } else{
                if( find(s1, s2 , s3 ,pathLen,pos1, pos2, v) ) {
                    found = true;
                }
            }


            pathLen--;
            pos2--;
        }
    }

    setFoundState(v, strlen(s1)+1, strlen(s2)+1, pos1, pos2, found);
    return found;
}

bool isInterleave(char* s1, char* s2, char* s3) {
    int pathLen = 0;
    int pos1 = 0;
    int pos2 = 0;
    if( strlen(s1) + strlen(s2) != strlen(s3) ) return false;
    unsigned char * v = calloc( 1, sizeof(unsigned char) * (strlen(s1)+1) * (strlen(s2)+1) );
    bool ret =  find(s1, s2 , s3 ,pathLen,pos1, pos2, v);
    free(v);
    return ret;
}


/*
void printPath( int * path, int len){

    printf("\n");
    for (int i = 0; i < len ; ++i) {
        printf( "%d ", path[i]);
    }
    printf("\n");

}

bool isInterleave(char* s1, char* s2, char* s3) {
    int * path = NULL;
    int pathLen = 0;
    int pos1 = 0;
    int pos2 = 0;
    if( strlen(s1) + strlen(s2) != strlen(s3) ) return false;
    path = calloc( 1, sizeof(int) * strlen(s3) );
    path[0] = 0;
    printPath(path,pathLen);
    int curSibling = 0;
    while(1){
        // found
        if( pos1 == strlen(s1) && pos2 == strlen(s2) ) return true;

        // traverse left
        if( curSibling == 0 &&  pos1 < strlen(s1) ){
            if( s1[pos1] == s3[pathLen]) {
                path[pathLen] = 0;
                pathLen++;
                pos1++;
                curSibling = 0;
                printPath(path,pathLen);
                continue;
            }
        }
        curSibling = 1;

        // traverse right
        if( curSibling == 1 && pos2 < strlen(s2) ){
            if( s2[pos2] == s3[pathLen]){
                path[pathLen] = 1;
                pathLen++;
                pos2++;
                curSibling = 0;
                printPath(path,pathLen);
                continue;
            }
        }

        // return
        if( pathLen == 0 ){
            return false;
        }

        // back trace
        while( pathLen > 0 ) {
            if( path[pathLen] == 0 ){
                pathLen--;
                pos1--;
                curSibling = 1;
                printPath(path,pathLen);
                break;
            } else{
                pathLen--;
                pos2--;
                printPath(path, pathLen);
            }
        }
    }
}
*/


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
#endif //LEETCODE_M1_INTERLEAVINGSTRING_H
