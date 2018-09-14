#include <stdio.h>

#include "twoSum1.h"
#include "p97/m1_interleavingString97.h"
int main() {
    int array[3] = { 3,2,4 };
    int* ret = twoSum( array, 3, 6);
    printf( "p1:[%d,%d]\n", ret[0], ret[1] );

    /*
    char * p = calloc(1,100);
    p[200] = 'e';
    printf("%c",p[200]);
    free(p);

    unsigned char * v = calloc( 1, 3 * 3 );
    memset(v, 0,9);
    for( int i = 0; i < 9; i ++ ){
        printf("%d", (int)v[i]);
    }
    return 0;
    */

}