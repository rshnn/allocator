#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (){

    /*
        TESTCASE 02
        This request will be too large to handle.
    */
    printf("TESTCASE 02:\tRequest is too large.\n");    
    void *p1 = malloc(8200);
    free(p1);
    printf("\n");                


	return 0;
}
