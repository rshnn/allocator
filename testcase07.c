#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (){

    /* 
        TESTCASE 07
        Set of malloc requests where the last is not able to be satisifed due to space limitations. 
    */
    printf("TESTCASE 07:\tLast request cannot be satisified.\n");                
    void *p1 = malloc(3000);
    void *p2 = malloc(3000);
    void *p3 = malloc(3000);

    free(p1);
    free(p2);
    free(p3);
    printf("\n");      
    

    return 0;
}
