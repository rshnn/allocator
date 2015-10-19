#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (){

    /* 
        TESTCASE 01
        Set of successful allocations and deallocations 
    */
    printf("TESTCASE 01:\tProper allocation and free requests.\n");                
    void *p1 = malloc(100);
    void *p2 = malloc(200);
    void *p3 = malloc(300);
    free(p1);
    void *p4 = malloc(400);
    free(p2);
    free(p3);
    free(p4);
    printf("\n");      
    

    return 0;
}
