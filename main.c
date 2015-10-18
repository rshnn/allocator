#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (int argc, char **argv){

    /* Set of successful allocations and deallocations */
    void *p1 = malloc(100);
    void *p2 = malloc(75);
    void *p3 = malloc(50);
    void *p4 = malloc(125);
    free(p1);
    free(p2);
    free(p3);
    free(p4);


    /* Should be too large to handle */
    p1 = malloc(10000);



    return 0;
}
