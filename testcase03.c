#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (){

    /*
        TESTCASE 03
        Requesting zero and negative memory space.
    */
    printf("TESTCASE 03:\tRequesting invalid sizes.\n");
    void *p1 = malloc(-10);
    void *p2 = malloc(0);
    free(p1);
    free(p2);
    printf("\n");                


	return 0;
}
