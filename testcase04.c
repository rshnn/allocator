#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (){

    /*
        TESTCASE 04 
        Redundant freeing of pointer.
    */
    printf("TESTCASE 04:\tRedundant freeing of a pointer.\n"); 
    void *p1 = malloc(15);
    free(p1);
    free(p1);
    printf("\n");                


	return 0;
}
