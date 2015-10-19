#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (){

    /*
        TESTCASE 06
        The block structure is corrupted by writing using an invalid pointer.   
    */

    printf("TESTCASE 06:\tCorrupting heap structure.\n");
    char *p1 = (char*)malloc(50);
    strcpy(p1-sizeof(memEntry),"Mustafar");
    char *p2 = (char*)malloc(50);
    if(p2!=NULL)
        free(p2);
    printf("\n");   

    return 0;             
}
